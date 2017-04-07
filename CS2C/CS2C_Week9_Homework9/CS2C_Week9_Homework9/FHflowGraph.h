/*
Created by Connor Lynch
CS2C, Advanced Data Structures & Algorithms in C++
Created March 11, 2017
Professor Dave Harden
Assignment 9.1


Description: This program lays out the the template class FHflowGraph which 
 is used to implement the maximum flow graph algorithm. A flow graph is 
 initialized by taking user input for vertices and their connections. All 
 paths from the desired source and sink of the graph are probed using 
 breadth first search (modified dikjstra's algorithm). For each path found 
 the minimum flow (connection) is determine and used to decrement the residual
 graph and increment the flow graph. To compute the total flow, all flow cost
 from the source to sink are summed and reported.


FHflowvertex:
Member Functions:

 void addToFlowAdjList(VertPtr neighbor, CostType cost);
 Precondition: A FHflowvertex object exists
 Postcondition: A FHflowvertex object exists with an additional pair added to 
 the FlowAdjList map for containing cost

 void addToResAdjList(VertPtr neighbor, CostType cost);
 Precondition: A FHflowvertex object exists
 Postcondition: A FHflowvertex object exists with an additional pair added to
 the FlowAdjList map for containing cost (set as const 0)

showFlowAdjList()
 Precondition: A FHflowvertex object exists
 Postcondition: The data and cost of each vertex in the FHflowvertex 
 adjecenty list is output to console

showResAdjList()
 Precondition: A FHflowvertex object exists
 Postcondition: The data and cost of each vertex in the FHflowvertex
 residual list is output to console
 
CostType sumFlowAdjList()
 Precondition: A FHflowvertex object exists
 Postcondition:Returns sum of flows between vertex and its neighbors


FHflowGraph:
Member Functions:

CostType findMaxFlow()
Precondition: A FHflowGraph exists
Postcondition: The flowAdjList and resAdjList are modified to produce the max
 flow calculation between startVertPtr, endVertPtr, the maximum flow between 
 the two vertices is returned

bool establishNextFlowPath()
 Precondition: A FHflowGraph exists which may or may not have a possible path 
 from startVertPtr to endVertPtr
 Postcondition: The vertices nextInPath data is modified to produce a sudo
 linked list between StartVertPtr and endVertPtr is a possible path exits. 
 Returns true if possible path can be generated, false otherwise.

CostType getLimitingFlowOnResPath()
 Precondition: A sudo linked list between two VertPtrs exits in the residual 
 adjacenct list
 Postcondition: The minimum flow in the path between two linked VertPtrs is 
 returned

bool adjustPathByCost(CostType cost)
 Precondition: A sudo linked list between two VertPtrs exits in the residual
 adjacent list and flow adjacent
 Postcondition: The residual forward connection adjacent list is reduced to
 indicate the loss of direct flow, whiel the residual reverse connections are 
 increase by cost. The flow adjacent list are increased by cost for VertPtrs 
 on path between the two VertPtrs.

CostType getCostOfResEdge(VertPtr src, VertPtr dst)
 Precondition: dst is contained within src's residual adjacent list
 Postcondition: Returns the associate cost of the connect between 
 src and dst on the FHflowGraph

bool addCostToResEdge(VertPtr src, VertPtr dst, CostType cost)
 Precondition: dst is contained within src's residual adjacent list
 Postcondition: Cost is added to the cost variable for the connection 
 between src and dst

bool addCostToFlowEdge(VertPtr src, VertPtr dst, CostType cost)
 Precondition: dst is contained within src's flow adjacent list or src is 
 contained within dst's flow adjacent list
 Postcondition: Cost is added to the cost variable for the connection between 
 src and dst, if the connection does not exist, Cost is added to the 
 cost variable between dst and src.
*/

#ifndef FHGRAPH_H
#define FHGRAPH_H
#include <limits.h>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iostream>
#include <functional>
using namespace std;




class FHflowGraphException {};

template <class Object, typename CostType>
class FHflowvertex
{
   // internal typedefs to simplify syntax
   typedef FHflowvertex<Object, CostType>* VertPtr;
   typedef map<VertPtr, CostType> EdgePairList;

public:
   static int nSortKey;
   static stack<int> keyStack;
   static enum { SORT_BY_DATA, SORT_BY_DIST } eSortType;
   static bool setNSortType( int whichType );
   static void pushSortKey() { keyStack.push(nSortKey); }
   static void popSortKey() { nSortKey = keyStack.top(); keyStack.pop(); }

   static int const INFINITY_FH = INT_MAX;
   EdgePairList  flowAdjList, resAdjList;
   Object data;
   CostType dist;
   VertPtr nextInPath;

   FHflowvertex( const Object & x = Object() );

   void addToFlowAdjList(VertPtr neighbor, CostType cost);
   void addToResAdjList(VertPtr neighbor, CostType cost);

   bool operator<( const FHflowvertex<Object, CostType> & rhs) const;
   const FHflowvertex<Object, CostType> & operator=
   ( const FHflowvertex<Object, CostType> & rhs);
   void showFlowAdjList();
   void showResAdjList();
   CostType sumFlowAdjList();
};

template <class Object, typename CostType>
int FHflowvertex<Object, CostType>::nSortKey
= FHflowvertex<Object, CostType>::SORT_BY_DATA;

template <class Object, typename CostType>
stack<int> FHflowvertex<Object, CostType>::keyStack;






template <class Object, typename CostType>
bool FHflowvertex<Object, CostType>::setNSortType( int whichType )
{
   switch (whichType)
   {
      case SORT_BY_DATA:
      case SORT_BY_DIST:
         nSortKey = whichType;
         return true;
      default:
         return false;
   }
}







template <class Object, typename CostType>
FHflowvertex<Object, CostType>::FHflowvertex( const Object & x)
: data(x), dist((CostType)INFINITY_FH),
nextInPath(NULL)
{
}







template <class Object, typename CostType>
void FHflowvertex<Object, CostType>::addToFlowAdjList
(FHflowvertex<Object, CostType> *neighbor, CostType cost)
{
    flowAdjList[neighbor] = cost;
}







template <class Object, typename CostType>
void FHflowvertex<Object, CostType>::addToResAdjList
(FHflowvertex<Object, CostType> *neighbor, CostType cost)
{
   resAdjList[neighbor] = cost;
}







template <class Object, typename CostType>
bool FHflowvertex<Object, CostType>::operator<(
                                           const FHflowvertex<Object, CostType> & rhs) const
{
   switch (nSortKey)
   {
      case SORT_BY_DIST:
         return (dist < rhs.dist);
      case SORT_BY_DATA:
         return (data < rhs.data);
      default:
         return false;
   }
}







template <class Object, typename CostType>
const FHflowvertex<Object, CostType> & FHflowvertex<Object, CostType>::operator=(
                                                                         const FHflowvertex<Object, CostType> & rhs)
{
   flowAdjList = rhs.adjList;
   data = rhs.data;
   dist = rhs.dist;
   nextInPath = rhs.nextInPath;;
   return *this;
}







template <class Object, typename CostType>
void FHflowvertex<Object, CostType>::showFlowAdjList()
{
   typename EdgePairList::iterator iter;

   cout << "Adj Flow List for " << data << ": ";
   for (iter = flowAdjList.begin(); iter != flowAdjList.end(); ++iter)
      cout << iter->first->data << "(" << iter->second << ") ";
   cout << endl;
}







template <class Object, typename CostType>
void FHflowvertex<Object, CostType>::showResAdjList()
{
   typename EdgePairList::iterator iter;

   cout << "Adj Res List for " << data << ": ";
   for (iter = resAdjList.begin(); iter != resAdjList.end(); ++iter)
   cout << iter->first->data << "(" << iter->second << ") ";
   cout << endl;
}






template <class Object, typename CostType>
CostType FHflowvertex<Object, CostType>::sumFlowAdjList()
{
   typename EdgePairList::iterator iter;
   CostType flowSum = 0;

   for (iter = flowAdjList.begin(); iter != flowAdjList.end(); ++iter)
      flowSum += iter->second;
   return flowSum;
}






template <class Object, typename CostType>
class FHflowGraph
{
   // internal typedefs to simplify syntax
   typedef FHflowvertex<Object, CostType> Vertex;
   typedef FHflowvertex<Object, CostType>* VertPtr;
   typedef map<VertPtr, CostType> EdgePairList;
   typedef set<VertPtr> VertPtrSet;
   typedef set<Vertex> VertexSet;

private:
   VertPtrSet vertPtrSet;
   VertexSet vertexSet;
   VertPtr startVertPtr, endVertPtr;

public:
   FHflowGraph () {}
   void addEdge(const Object &source, const Object &dest, CostType cost);
   VertPtr addToVertexSet(const Object & object);
   void Table();
   void clear();
   void showFlowAdjTable();
   void showResAdjTable();
   bool setStartVert(const Object &x);
   bool setEndVert(const Object &x);
   CostType findMaxFlow();

private:
   VertPtr getVertexWithThisData(const Object & x);
   bool establishNextFlowPath();
   CostType getLimitingFlowOnResPath();
   bool adjustPathByCost(CostType cost);
   CostType getCostOfResEdge(VertPtr src, VertPtr dst);
   bool addCostToResEdge(VertPtr src, VertPtr dst, CostType cost);
   bool addCostToFlowEdge(VertPtr src, VertPtr dst, CostType cost);
};






//Member function takes an object, and converts it to a vertex object
//storying it in the vertex Set of flow graph
template <class Object, typename CostType>
FHflowvertex<Object, CostType>* FHflowGraph<Object, CostType>::addToVertexSet(
                                                                      const Object & object)
{
   pair<typename VertexSet::iterator, bool> retVal;
   VertPtr vPtr;

   // save sort key for client
   Vertex::pushSortKey();
   Vertex::setNSortType(Vertex::SORT_BY_DATA);

   // build and insert vertex into master list
   retVal = vertexSet.insert( Vertex(object) );

   // get pointer to this vertex and put into vert pointer list
   vPtr = (VertPtr)&*retVal.first;
   vertPtrSet.insert(vPtr);

   Vertex::popSortKey();  // restore client sort key
   return vPtr;
}







template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::clear()
{
   vertexSet.clear();
   vertPtrSet.clear();
}






//member function takes source and dest objects, and their associatated costs
//adding dest with cost of cost to the flowAdjList of src, the resAdjList of src
//and the resAdjlist of dst
template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::addEdge(const Object &source,
                                            const Object &dest, CostType cost )
{
   VertPtr src, dst;
   const int REVERSE_COST = 0;

   // put both source and dest into vertex list(s) if not already there
   src = addToVertexSet(source);
   dst = addToVertexSet(dest);

   // add dest to source's flow and residual lists
   src->addToFlowAdjList(dst, REVERSE_COST);
   src->addToResAdjList(dst, cost); //This is the forward edge
   dst->addToResAdjList(src, REVERSE_COST);
}






//Member function displays the contents of flowAdjTable
template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::showFlowAdjTable()
{
   typename VertPtrSet::iterator iter;

   cout << "---------- Flow Adjacency Table ----------\n";
   for (iter = vertPtrSet.begin(); iter != vertPtrSet.end(); ++iter)
   (*iter)->showFlowAdjList();
   cout << endl;
}






//Member function displays the contents of resAdjTable
template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::showResAdjTable()
{
   typename VertPtrSet::iterator iter;

   cout << "---------- Residual Adjacency Table ----------\n";
   for (iter = vertPtrSet.begin(); iter != vertPtrSet.end(); ++iter)
   (*iter)->showResAdjList();
   cout << endl;
}






//Member function takes Object x, and sets startVertPtr to the memory location
//of the vertex that contains that object, returns false otherwise
template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::setStartVert(const Object &x)
{
   startVertPtr = getVertexWithThisData(x);

   return startVertPtr == NULL;
}






//Member function takes Object x, and sets endVertPtr to the memory location
//of the vertex that contains that object, returns false otherwise
template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::setEndVert(const Object &x)
{
   endVertPtr = getVertexWithThisData(x);
   
   return startVertPtr == NULL;
}







template <class Object, typename CostType>
FHflowvertex<Object, CostType>* FHflowGraph<Object, CostType>::getVertexWithThisData(
                                                                             const Object & x)
{
   typename VertexSet::iterator findResult;
   Vertex vert(x);

   Vertex::pushSortKey();  // save client sort key
   Vertex::setNSortType(Vertex::SORT_BY_DATA);
   findResult = vertexSet.find(vert);
   Vertex::popSortKey();

   if ( findResult == vertexSet.end() )
      return NULL;
   return  (VertPtr)&*findResult;
}






//Member function determines the maximum flow for a given FHflowGraph by
//first callign on establishNextFlowPath, then getLimitingFlowResPath
//then adjusting the flow and res adjacent lists, finally calculating the
//flow sum
template <class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::findMaxFlow()
{
   CostType totalFlow = 0;
   int flowLimit;
   bool pathEstablished, pathAdjusted;

   while (true)
   {
      pathEstablished = establishNextFlowPath();
      flowLimit = getLimitingFlowOnResPath();
      pathAdjusted = adjustPathByCost(flowLimit);

      if ((!pathEstablished) || (flowLimit == 0))
         break;
   }

   //Finally, the flow graph is probed to find the total flow
   typename VertPtrSet::iterator iter;
   for (iter = vertPtrSet.begin(); iter != vertPtrSet.end(); ++iter)
      totalFlow += (*iter)->sumFlowAdjList();

   return totalFlow;
}






//Member function reproduces the dijkstra's breadth first search algorithm
//in order to establish a sudo linked list between startVertPtr and
//endVertPtr
template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::establishNextFlowPath()
{
   typename VertPtrSet::iterator vIter;
   typename EdgePairList::iterator edgePrIter;
   VertPtr wPtr, sPtr, vPtr;
   CostType costVW;
   queue<VertPtr> partiallyProcessedVerts;

   sPtr = startVertPtr;
   if (sPtr == NULL)
      return false;

   for (vIter = vertPtrSet.begin(); vIter != vertPtrSet.end(); ++vIter)
   {
      (*vIter)->dist = Vertex::INFINITY_FH;
      (*vIter)->nextInPath = NULL;
   }

   sPtr->dist = 0;
   partiallyProcessedVerts.push( sPtr );

   while( !partiallyProcessedVerts.empty() )
   {
      vPtr = partiallyProcessedVerts.front();
      partiallyProcessedVerts.pop();

      for (edgePrIter = vPtr->resAdjList.begin();
           edgePrIter != vPtr->resAdjList.end();
           edgePrIter++)
      {
         wPtr = edgePrIter->first;
         costVW = edgePrIter->second;

         if (costVW > 0)
         {
            wPtr->dist = vPtr->dist + costVW;
            wPtr->nextInPath = vPtr;
            partiallyProcessedVerts.push(wPtr);
         }

         if (wPtr == endVertPtr)
            return true;
      }
   }
   return true;
}






//Member function determines the minimum flow between two vertices along the
//path between startVertPtr and endVertPtr returning that value
template <class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::getLimitingFlowOnResPath()
{
   VertPtr vp, prevVp;
   CostType tempFlowLimit, flowLimit = INT_MAX;
   stack<VertPtr> pathStack;

   if ((startVertPtr == NULL) || (endVertPtr == NULL))
      throw FHflowGraphException();

   for (vp = endVertPtr; vp != startVertPtr; vp = vp->nextInPath)
   {
   if ( vp->nextInPath == NULL )
         return false;
      pathStack.push(vp);
   }
   pathStack.push(vp);


   prevVp = pathStack.top();
   pathStack.pop();
   
   while (true)
   {
      vp = pathStack.top();
      pathStack.pop();
      tempFlowLimit = getCostOfResEdge(prevVp, vp);
      if (tempFlowLimit < flowLimit)
         flowLimit = tempFlowLimit;

      prevVp = vp;

      if ( pathStack.empty() )
         break;
   }

   return flowLimit;
}






//Member function takes a cost value and adjusts the flow and residual graphs
//edges by that value. Function returns true if both adjustment operations
//are successful, false otherwise.
template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::adjustPathByCost(CostType cost)
{
   bool adjustedFlow, adjustedRes;
   VertPtr vp, prevVp;
   CostType tempFlowLimit, flowLimit = INT_MAX;
   stack<VertPtr> pathStack;

   for (vp = endVertPtr; vp != startVertPtr; vp = vp->nextInPath)
   {
      if ( vp->nextInPath == NULL )
         return false;
      pathStack.push(vp);
   }
   pathStack.push(vp);

   prevVp = pathStack.top();
   pathStack.pop();

   while (true)
   {
      vp = pathStack.top();
      pathStack.pop();
      adjustedFlow = addCostToFlowEdge(prevVp, vp, cost);
      adjustedRes = addCostToResEdge(prevVp, vp, cost);

      prevVp = vp;

      if ( pathStack.empty() )
      break;
   }

   return (adjustedFlow) && (adjustedRes);
}






//Member function determined the cost between VertPtr src and the VrtPtr
//dst in src's adjacent list return CostType dist
template <class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::getCostOfResEdge(VertPtr src,
                                                         VertPtr dst)
{
   CostType dist;
   typename EdgePairList::iterator iter = src->resAdjList.begin();

   while(iter->first != dst)
      ++iter;

   dist = iter->second;

   return dist;
}






//Member function takes VertPtr src, dst and CostType cost removing that value
//from the dst object in src's residual list
template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::addCostToResEdge(VertPtr src,
                                                     VertPtr dst, CostType cost)
{
   if ((src == NULL) || (dst == NULL))
      return false;

   typename EdgePairList::iterator iter;

   for (iter = src->resAdjList.begin();
        iter != src->resAdjList.end(); ++iter)
   {
      if (iter->first == dst)
      {
         iter->second -= cost;
         return true;
      }
   }
   return false;
}






//Member function akes VertPtr src, dst and CostType cost. If dst is located
//in src's flow adjacent list, then cost is added to dst cost, othersise if
//src is located in dst flow adjacent list, then cost is subtracted from src cost
template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::addCostToFlowEdge(VertPtr src,
                                                      VertPtr dst, CostType cost)
{
   if ((src == NULL) || (dst == NULL))
      return false;

   typename EdgePairList::iterator iter;
   for (iter = src->flowAdjList.begin();
        iter != src->flowAdjList.end(); ++iter)
   {
      if (iter->first == dst)
      {
         iter->second += cost;
         return true;
      }
   }


   for (iter = dst->flowAdjList.begin();
        iter != dst->flowAdjList.end(); ++iter)
   {
      if (iter->first == src)
      {
         iter->second -= cost;
         return true;
      }
   }

   return false;
}


#endif






/*-------------------------- Connor's Output ---------------------------

---------- Residual Adjacency Table ----------
Adj Res List for s: a(3) b(2) 
Adj Res List for a: s(0) b(1) c(3) d(4) 
Adj Res List for b: s(0) a(0) d(2) 
Adj Res List for c: a(0) t(2) 
Adj Res List for d: a(0) b(0) t(3) 
Adj Res List for t: c(0) d(0) 

---------- Flow Adjacency Table ----------
Adj Flow List for s: a(0) b(0) 
Adj Flow List for a: b(0) c(0) d(0) 
Adj Flow List for b: d(0) 
Adj Flow List for c: t(0) 
Adj Flow List for d: t(0) 
Adj Flow List for t: 

Final flow: 6
---------- Residual Adjacency Table ----------
Adj Res List for s: a(1) b(2) 
Adj Res List for a: s(0) b(1) c(1) d(4) 
Adj Res List for b: s(0) a(0) d(2) 
Adj Res List for c: a(0) t(0) 
Adj Res List for d: a(0) b(0) t(3) 
Adj Res List for t: c(0) d(0) 

---------- Flow Adjacency Table ----------
Adj Flow List for s: a(2) b(0) 
Adj Flow List for a: b(0) c(2) d(0) 
Adj Flow List for b: d(0) 
Adj Flow List for c: t(2) 
Adj Flow List for d: t(0) 
Adj Flow List for t: 

Program ended with exit code: 0
 

 ---------------------------- End of Output ----------------------------*/






