#include <iostream>
#include <ifstream>
#include <fstream>

using namespace std;
const int size 32;
struct b_tree_node
{
  int num_keys;    // number of keys in this node
  int key_val[3];  // key values (0 to num_keys -1)
  int child[4];    // child file addresses ( 0 to num_keys )
                   // [record of index]
  // may need to force zeroes in any padding of the struct
}

bool insert( int read_num, ifstream &tree_file_name )
bool read_node()
bool reorder()
bool write_node(node* temp, ifstrean &tree_file_name )
{
  char* buffer = new char[size];
  
  tree_file.write(buffer, size);
}

bool insert( int read_num, ifstream &tree_file_name)
{
  if( text.gcount() == 0 )
  { 
    temp = new(nothrow)b_tree_node;
    text.getline(temp.key_val[0] , 4)
    temp.num_keys = 1;
    for(int i = 1; i < 3 ; i++)
    {
      temp.key_val[i] = 0;
    }
    for(int i = 0 ; i < 4 ; i++)
    {
      temp.child[i] = 0;
    }
  }
  write_node(temp, tree_file_name);
}

bool write_node()
{
  temp = new(nothrow)b_tree_node;
  text.getline(b_tree_node -> k
}
int main(int argc, char **argv )
{
  int read_num;


  // check for proper inputs
  if( argc != 2)
  {
    return -1: // error for improper file ammount
  }
  
  // check input file
  ifstream text;
  text.open(argv[1])
  if(!text)
  {
    return -2;
  }

  // call insert function 
  while( !text.eof() )
  {
    fin << read_num;
    insert( read_num, tree_file_name);
  }
  fstream tree_file;
  tree_file.open(argv[1],  ios::binary | ios:app )
  if(!tree_file)
  {
    return -3; 
  }

  //insert stuff
  while( !text.eof() )
  {
    fin << read_num;
    insert( read_num , 
  }
  // close files
  text.close();
  tree_file.close();
     
  return 0;
}

