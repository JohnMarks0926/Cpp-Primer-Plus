// vect3.cpp -- Using STL functions.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool cheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(std::shared_ptr<Review> & rr);
void ShowReview(const std::shared_ptr<Review> & rr);
int main()
{
	using namespace std;
	vector<shared_ptr<Review>> books;
	vector<shared_ptr<Review>> tempbooks;
	std::shared_ptr<Review> temp = make_shared<Review>();
	while (FillReview(temp))
	{
		books.push_back(make_shared<Review>(*temp));
		tempbooks.push_back(make_shared<Review>(*temp));
		temp = std::make_shared<Review>();
	}
	int c = 1;
	if (books.size() > 0)
	{
		while (c != 0)
		{
			cout << "Please enter the number you want to do:\n";
			cout << "1.Original arrangement, 2.Title sorted with alphabetical, \n"
				<< "3.Rating increasement, 4.Rating decreasement,\n"
				<< "5.Price increasement, 6.Price decreasement.\n"
				<< "o.Exit.\n";
			cin >> c;
			switch(c)
			{
				case 1:
					cout << "Original arrangement: \n"
						<< "Book\tRating\tPrice\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 2:
					cout << "2.Sorted by title:\n"
						<< "Book\tRating\tPrice\n";
					sort(tempbooks.begin(), tempbooks.end());
					for_each(tempbooks.begin(), tempbooks.end(), ShowReview);
					break;
				case 3:
					cout << "3. Sorted by increasing rating:\n"
						<< "Book\tRating\tPrice\n";
					sort(tempbooks.begin(), tempbooks.end(), worseThan);
					for_each(tempbooks.begin(), tempbooks.end(), ShowReview);
					break;
				case 4:
					cout << "4. Sorted by decreasing rating:\n"
						<< "Book\tRating\tPrice\n";
					sort(tempbooks.begin(), tempbooks.end(), worseThan);
					for_each(tempbooks.rbegin(),tempbooks.rend(), ShowReview);
					break;
				case 5:
					cout << "5. Sorted by increasing price:\n"
						<< "Book\tRating\tPrice\n";
					sort(tempbooks.begin(), tempbooks.end(), cheaperThan);
					for_each(tempbooks.begin(), tempbooks.end(), ShowReview);
					break;
				case 6:
					cout << "6. Sorted by decreasing price:\n"
						<< "Book\tRating\tPrice\n";
					sort(tempbooks.begin(), tempbooks.end(), cheaperThan);
					for_each(tempbooks.rbegin(), tempbooks.rend(), ShowReview);
					break;
				case 0:
					cout << "Bye.\n";
					break;
			}
		}
	}
	
	return 0;
}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool cheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

bool FillReview(std::shared_ptr<Review> & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr->title);
	if (rr->title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr->rating;
	if (!std::cin)
		return false;
	std::cout << "Enter book price: ";
	std::cin >> rr->price;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const std::shared_ptr<Review> & rr)
{
	std::cout << rr->title << "\t" << rr->rating << "\t" << rr->price << std::endl;
}
