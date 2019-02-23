//DAY 13



// Write your MyBook class here
class MyBook : public Book {
public:
  MyBook(string t, string a, int p) : Book(t, a), price(p) {}

  virtual void display(void) override {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Price: " << price << endl;
  }

private:
  int price;
};

//   Class Constructor
//
//   Parameters:
//   title - The book's title.
//   author - The book's author.
//   price - The book's price.
//
// Write your constructor here

//   Function Name: display
//   Print the title, author, and price in the specified format.
//
// Write your method here
    
// End class

