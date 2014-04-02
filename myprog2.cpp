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

void insert( fstream &tree_file, int read_num );
bool is_leaf( fstream &tree_file, int node_num );
void pad_zero( b_tree_node node );
void split_node( fstream &tree_file, b_tree_node ins_node );

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
  ild is a leaf, insert the value
    //
    //return -1: // error for improper file ammount
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
    insert( read_num, tree_file );
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

bool is_leaf ( fstream &tree_file, int node_num )
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
  }
  node.child[3] = 0;
}

void split_node ( fstream &tree_file, b_tree_node ins_node )
{
  int temp;
  int pos;
  
  //create left and right nodes, set to zero
  b_tree_node left_node;
  b_tree_node right_node;
  pad_zero( left_node );
  pad_zero( right_node );
  
  //assign nodes their respective values
  left_node.num_keys = 1;
  right_node.num_keys = 1;
  left_node.key_val[0] = ins_node.key_val[0];
  right_node.key_val[0] = ins_node.key_val[2];
  
  //move middle value, set back to zero, and place into first spot
  temp = ins_node.key_val[1];
  pad_zero( ins_node );
  ins_node.key_val[0] = temp;

  //write left 
  pos = tree_file.seekg( 0, ios::end );
  ins_node.child[0] = (pos/size);
  tree_file.write( (char*)&left_node, size );
  
  //write right
  pos = tree_file.seekg( 0 , ios::end );
  ins_node.child[2] = (pos/size);
  tree_file.write( (char*)&right_node, size );
}


void insert(ifstream &tree_file, int read_num, int node_num, int parent)
{
    int i;
    int temp;
    b_tree_node temp_node;
   
    //if(node @ tree_file_name is a 4 node, meaning 3 key values)
    tree_file.read((char*)&temp, size)
    if( temp.num_keys == 3 )
    {
        //split root
        if( tree_file.tellg() == 0 )
        {
          split( tree_file, temp_node );
        }
        else
          // rotate function.
    
         
    }
    for( i = 0; i < 3; i++ )
    {
      if( read_num < temp.key_val[i] )
      
    }

    // not 4 node
    
    //empty case    
   /* tree_file.seekg( 0 , ios::end );
    temp = tree_file.tellg();
    tree_file.seekg( 0 , ios::beg );
    if( temp == tree_file.tellg() )
    {
      
    }*/

    //if the child is a leaf, insert the value
    //
    //else
    //  seekg(tree_file_name, position of that node)
    //  insert(readnum, tree_file_name)
    //return;
}


int search_tree( ifstream &tree_file, int node_num, int read_num)
{
  b_tree_node temp_node;
  tree_file.seekg( (node_num*32) , ios::beg);
  tree_file.read( (char*) &temp, size);

  //base case
  if( is_leaf( tree_file, node_num ) )
     return node_num;

  if( num_key == 3 )
  {
    split( tree_file, temp_node);
  }

  for( int i = 0; i < 3 ; i++)
  {
    if( (read_num < temp.key_val[i]) && (temp.key_val[i] != 0)  )
    {
      search_tree(tree_file, temp.child[i] , read_num);
    }
    
    if( (read_num > temp.key_val[i]) && (temp.key_val[i] != 0) )
    {
      search_tree(tree_file, temp.child[i+1], read_num);
    } 
  }  
  
}
