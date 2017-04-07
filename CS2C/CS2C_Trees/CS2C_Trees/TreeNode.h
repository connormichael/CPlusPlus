//
//  TreeNode.h
//  CS2C_Trees
//
//  Created by Connor Lynch on 1/2/17.
//  Copyright (c) 2017 connor lynch. All rights reserved.
//

#ifndef __CS2C_Trees__TreeNode__
#define __CS2C_Trees__TreeNode__

#include <iostream>
#include "Tree.h"

namespace connor_tree
{
   class SearchTree;
   class TreeNode
   {
   public:
      friend class SearchTree; 
      typedef int value_type;
      TreeNode(value_type theData, TreeNode* leftLink, TreeNode* rightLink)
      : data(theData), left(leftLink), right(rightLink){};

      //private:
      value_type data;
      TreeNode* right;
      TreeNode* left;
   };

}

#endif /* defined(__CS2C_Trees__TreeNode__) */
