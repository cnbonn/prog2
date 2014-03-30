///////////////////////////////////////////////////////////////////////////////
//                              Prog 2                                       //
//                       234-Trees and Binary Files                          //
///////////////////////////////////////////////////////////////////////////////
//
//Brief: This program is designed to construct a 234-tree based off of a given
//       input file, by building the tree off of a binary output file, not by
//       building it in memory.
//
//File: prog2.cpp
//
//Date (Assigned...Due): 3/3/14...4/1/14
//
//Authors: Charles Bonn / Joseph Mowry
//
//Instructor: Dr. Corwin
//
//Description: [stuff]

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

void insert( int read_num, ifstream &tree_file_name );
bool read_node();
bool reorder();

void read_node ( b_tree_node node, fstream &fout, int curr_node )
{
  int temp;
  
  fout.seekg ( 0, ios::beg );
  fout.read ( node, 32 );
}

bool write_node( b_tree_node node, fstream &fout, int read_num )
{
  //nick
  
}

void tree_insert ( int read_num, fstream &fout  )
{
  read_node( node, fout, curr_node );
  //check to see if 4-node
  int temp;
  int i;
  fout.seekg ( 0, ios::beg );
  fout.read ( temp, 4 );
  
  //empty case
  if( node.num_keys == 0 )
    write_node( node, fout, read_num, 0 );

  else if( node.num_keys < 3 )
  {
    for(i = 0; i < 3; i++ )
    {
      if( node.key_val[i] > read_num )
      {
        temp = key_val[i];
        key_val[i] = read_num;
      }
    }
  }
  else
  {
    //split, etc
    temp = node.key_val[1]; //save middle val
    node.key_val[1] = 0;    //and remove it
    
    new(nothrow) b_tree_node leftnode = {};
    new(nothrow) b_tree_node rightnode = {};
    new(nothrow) b_tree_node root = {};

    
    
  } 
}

bool is_leaf ( fstream &fout, int node_num )
{
  int i = 0;
  int temp = 0; //placeholder to check child
  tree_file_name.seekg( i, ios::beg );
  for( i = ( ( node_num * 32) + 16 ); i < ( ( node_num + 1 ) * 32); )
  {
    tree_file_name.read( temp, 4 ); //read child into temp
    i += 4; //increment to next child
    
    if( temp != 0)  //indicates child...not a leaf
      return false;
  }  
  return true;
}

void split_node ( fstream &fout )
{
  
}

int main(int argc, char **argv )
{
  int read_num;
  b_tree_node node = {};  //init all members to 0
  ifstream text;
  fstream fout;

  // check for proper inputs
  if( argc != 3)
  {
    return -1: // error for improper file ammount
  }
  
  text.open( argv[0] );
 
  if(!text)
  {
    return -2;
  }
  
  fout.open( argv[1], ios::binary );  

  if(!tree_file)
  {
    return -3;
  }
  
  while( !text.eof() )
  {
    text >> read_num;
    read_node( node, 
    insert( read_num, fout );
  }

  // close files
  text.close();
  tree_file.close();

  return 0;
}

