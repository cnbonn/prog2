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
bool is_leaf( fstream &fout, int node_num );
bool read_node(   );
void split_node(   );
void tree_insert(   );
void write_node(   );

int main(int argc, char **argv )
{
  int read_num;
  int i;
  b_tree_node ins_node = {0};  //init all members to 0
  ifstream text;
  fstream tree;

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
  
  tree.open( argv[1], ios::binary );  

  if(!tree_file)
  {
    return -3;
  }

  while( fin >> read_num )  //while text file not empty
  { 
    if( num_keys == 3 ) 
      split_node( ins_nod );
    
    for( i = 0; ins_node.key_val[i] > ins_node.read_num; i++ )
    {
      temp = ins_node.key_val[i];
      ins_node.key_val[i] = ins_node.read_num;
      ins_node.read_num = temp;
    } 

    /*while( tree.read( char*( &ins_node ), size ) )
    {
      if( 
      read_node( node, 
      insert( read_num, fout );
     }*/
  }
  // close files

  free_tree();
  text.close();
  tree_file.close();

  return 0;
}

bool is_leaf ( fstream &fout, int node_num )
{
  int i = 0;
  int temp = 0; //placeholder to check child
  tree_file_name.seekg( i, ios::beg );
  for( i = ( ( node_num * size) + (size/2) ); i < ( ( node_num + 1 ) * size); )
  {
    tree_file_name.read( temp, 4 ); //read child into temp
    i += 4; //increment to next child
    
    if( temp != 0)  //indicates child...not a leaf
      return false;
  }  
  return true;
}

void pad_zero ( b_tree_node node )
{
  int i;  

  node.num_keys = 0;
  for( i = 0; i < 3; i++ )
  {
    node.key_val[i] = 0;
    node.child[i] = 0;
    node.child[i+1] = 0;
  }
}

void split_node ( b_tree_node ins_node )
{
  int temp;

  b_tree_node* left_node = new(nothrow) b_tree_node;
  b_tree_node* right_node = new(nothrow) b_tree_node;
  pad_zero( left_node );
  pad_zero( right_node );
  
  left_node.num_keys = 1;
  right_node.num_keys = 1;
  left_node.key_val[0] = ins_node.key_val[0];
  right_node.key_val[0] = ins_node.key_val[2];
  
  temp = ins_node[1];
  pad_zero( ins_node );
  ins_node[1] = temp;
}

void free_tree( b_tree_node node );
{
  if( is_leaf( node ) )
    delete node;
  
  else
  {
    for( i = 0; i < 4; i++ )
    {
      delete node.child[i];
    }
  
}

void insert( int readnum, ifstream &tree_file)
{
    //if(node @ tree_file_name is a 4 node, meaning 3 key values)
    if( tree_file.seekg( 0 , ios::beg ) == 3)
    {
    //  temp = key_value[1]
    //  split(node) gives you two 2-nodes
        split( node );
    //  if(tellg(tree_file_name) == 0) //root
        if( tellg( tree_file ) == 0 )
    //    write the pair of  2-nodes at the end of the file
          write( tree_file );
    
    //for each key value, check if readnum fits betwwen them
    //
    //if the child is a leaf, insert the value
    //
    //else
    //  seekg(tree_file_name, position of that node)
    //  insert(readnum, tree_file_name)
    //return;
}
