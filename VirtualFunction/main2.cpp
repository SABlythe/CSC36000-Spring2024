#include <iostream>
#include <list>

#include "Book.hpp"
#include "Media.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  list<Media> mediaList;
  list<Media*> mediaPtrList;

  Media m1, m2, m3; 
  Book b1, b2, b3;

  mediaList.push_back(m1);
  mediaList.push_back(m2);
  mediaList.push_back(m3);
  mediaList.push_back(b1);
  mediaList.push_back(b2);
  mediaList.push_back(b3);

  for (Media m:mediaList)
   cout << m.getTitle() << "<===>" << m.info() << endl;

  cout << endl << endl << endl;

  mediaPtrList.push_back(&m1);
  mediaPtrList.push_back(&m2);
  mediaPtrList.push_back(&m3);
  mediaPtrList.push_back(&b1);
  mediaPtrList.push_back(&b2);
  mediaPtrList.push_back(&b3);

  for (Media *m:mediaPtrList)
   cout << m->getTitle() << "<===>" << m->info() << endl;

  return 0;
}
