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
#include <fstream>

using namespace std;

const int size = 32;

struct b_tree_node
{
  int num_keys;    // number of keys in this node
  int key_val[3];  // key values (0 to num_keys -1)
  int child[4];    // child file addresses ( 0 to num_keys )
                   // [record of index]
  // may need to force zeroes in any padding of the struct
};
void copy_count( b_tree_node node );
void insert( fstream &tree_file, int read_num , int node_num, int parent );
bool is_leaf( fstream &tree_file, int node_num );
void pad_zero( b_tree_node node );
void rotate_node( fstream &tree_file, int read_num, int node_num, int parent );
void split_node( fstream &tree_file, b_tree_node ins_node );

int main( int argc, char **argv )
{
  int read_num;
  int i;
  b_tree_node ins_node = {0};  //init all members to 0
  ifstream text;
  fstream tree;

  // check for proper inputs
  if( argc != 3)
  {
   return -1;
  }
  
  text.open( argv[1] );
 
  if( !text )
  {
    return -2;
  }
  
  tree.open( argv[2], ios::in | ios::out | ios::binary );  
  if(!tree)
  {
    return -3;
  }

  while( text >> read_num )  //while text file not empty
  {
    insert( tree, read_num, 0, 0 );
    /*while( tree.read( char*( &ins_node ), size ) )
    {
      if( 
      read_node( node, 
      insert( read_num, fout );
     }*/
  }
  // close files
  text.close();
  tree.close();

  return 0;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void copy_count( b_tree_node node )
{
  int i;
  node.num_keys = 0;
  for( i = 0; i < 3; i++ )
  {
    if( node.key_val[i] != 0 )
      node.num_keys++;
  }
}
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////// 
void insert( fstream &tree_file, int read_num, int node_num, int parent )
{
  int i;
  int temp;
  b_tree_node temp_node;
  tree_file.seekg( ( node_num*size ) , ios::beg);
  tree_file.read( (char*) &temp_node, size);  
  tree_file.clear();

  

  //if(node @ tree_file_name is a 4 node, meaning 3 key values)
  if( temp_node.num_keys == 3 )
  {
      //split root
      if( tree_file.tellg() == 0 )
      {
        split_node( tree_file, temp_node );
      }
      else
        rotate_node( tree_file, read_num, node_num, parent );
    
  }
  //base case
  if( is_leaf( tree_file, node_num ) )
  {
    if( read_num < temp_node.key_val[0] || temp_node.key_val[0] == 0 )
    {
      temp_node.key_val[2] = temp_node.key_val[1];
      temp_node.key_val[1] = temp_node.key_val[0];
      temp_node.key_val[0] = read_num;
    }
    
    else if( read_num < temp_node.key_val[1] || temp_node.key_val[1] == 0 )
    {
      temp_node.key_val[2] = temp_node.key_val[1];
      temp_node.key_val[1] = read_num;
    }
    else
      temp_node.key_val[2] = read_num;

    temp_node.num_keys += 1;
    tree_file.seekp( node_num*size, ios::beg );
    tree_file.write( "fuck", 4 );
    return;
  }
 
  // recursive calls  
  for( int i = 0; i < 3; i++ )
  {
    if( ( read_num < temp_node.key_val[i] ) && ( temp_node.key_val[i] != 0 ) )
    {
      insert( tree_file, read_num, temp_node.child[i], parent );
    }
    
    if( ( read_num > temp_node.key_val[i] ) && ( temp_node.key_val[i] !=0 ) )
    {
      insert( tree_file, read_num, temp_node.child[i+1], parent );
    }
  }

    
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool is_leaf( fstream &tree_file, int node_num )
{
  int i = 0;
  int temp = 0; //placeholder to check child
  tree_file.seekg( i, ios::beg );
  for( i = ( ( node_num*size )+( size/2 ) ); i < ( ( node_num+1 )*size); )
  {
    tree_file.read( (char *) &temp, 4 ); //read child into temp
    i += 4; //increment to next child
    
    if( temp != 0 )  //indicates child...not a leaf
      return false;
  }  
  return true;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void pad_zero( b_tree_node node )
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
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void rotate_node( fstream &tree_file, int read_num, int node_num, int parent )
{
  int temp;
 // create node and set to zero
  b_tree_node temp_node;
  b_tree_node parent_node;
  b_tree_node child_node;
  pad_zero( temp_node );
  pad_zero( parent_node );
  pad_zero( child_node );

  //fill nodes
  tree_file.seekg( ( node_num*32 ) , ios::beg);
  tree_file.read( (char*) &child_node, size);
  tree_file.seekg( ( parent*32 ) , ios::beg);
  tree_file.read( (char*) &parent_node, size);

  //find value
  if( node_num == parent_node.child[0] )
  {
    // move parent key values to the right
    parent_node.key_val[2] = parent_node.key_val[1];
    parent_node.key_val[1] = parent_node.key_val[0];
    // move up child value to parent
    parent_node.key_val[0] = child_node.key_val[1];
    // move child pointers to the right
    parent_node.child[3] = parent_node.child[2];
    parent_node.child[2] = parent_node.child[1];
    parent_node.child[1] = parent_node.child[0];
    //find place of new child
    tree_file.seekg( 0 , ios::end );
    parent_node.child[0] = ( tree_file.tellg()/size );
    // save value to new node
    temp_node.key_val[0] = child_node.key_val[0];
    temp = child_node.key_val[2];
    pad_zero(child_node);
    child_node.key_val[0] = temp;
    //write nodes to file
    tree_file.write( ( char* ) &temp_node, size);
    tree_file.seekg(( parent*size ), ios::beg);
    tree_file.write( ( char* ) &parent_node, size);
    tree_file.seekg( ( node_num*size ), ios::beg);
    tree_file.write( ( char* ) &child_node, size);
  }
  else if( node_num == parent_node.child[1] )
  {
    //move key value 1 over
    parent_node.key_val[2] = parent_node.key_val[1];
    // move child up
    parent_node.key_val[1] = child_node.key_val[1];
    //move value to new node and save its pointer
    temp_node.key_val[0] = child_node.key_val[2];
    //reset child to 0
    temp = child_node.key_val[0];
    pad_zero(child_node);
    child_node.key_val[0] = temp;
    // find spot for new node
    tree_file.seekg( 0 , ios::end );
    parent_node.child[3] = ( tree_file.tellg()/size );
    //write to file
    tree_file.write( ( char* ) &temp_node, size );
    tree_file.seekg( ( parent*size ), ios::beg);
    tree_file.write( ( char* ) &parent_node, size );
    tree_file.seekg( ( node_num*size ), ios::beg );
    tree_file.write( (char*)&child_node, size);
  }
  else if( node_num == parent_node.child[2] )
  {
    //move child up
    parent_node.key_val[2] = child_node.key_val[1];
    //move value to new node and save its pointer
    temp_node.key_val[0] = child_node.key_val[2];
    //reset child to zero
    temp = child_node.key_val[0];
    pad_zero( child_node );
    child_node.key_val[0] = temp;
    //find spot for new node
    tree_file.seekg( 0, ios::end );
    parent_node.child[3] = ( tree_file.tellg() / size );
    //write it to the file
    tree_file.write( ( char* ) &temp_node, size );
    tree_file.seekg( ( parent*size ), ios::beg );
    tree_file.write( ( char* ) &parent_node, size );
    tree_file.seekg( ( node_num*size ), ios:: beg );
    tree_file.write( ( char* ) &child_node, size );
  }
  
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void split_node( fstream &tree_file, b_tree_node ins_node )
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
  tree_file.seekg( 0, ios::end );
  pos = tree_file.tellg();
  ins_node.child[0] = (pos/size);
  tree_file.write( ( char* ) &left_node, size );
  
  //write right
  tree_file.seekg( 0 , ios::end );
  pos = tree_file.tellg();
  ins_node.child[2] = ( pos/size );
  tree_file.write( ( char* ) &right_node, size );
}
