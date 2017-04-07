template <class Object>
class FHtreeNode
{
   // members not shown ...

public:
   FHtreeNode( const Object & d = Object(),
              FHtreeNode *sb = NULL, FHtreeNode *chld = NULL, FHtreeNode *prv = NULL )
   : firstChild(chld), sib(sb), prev(prv), data(d), myRoot(NULL)
   { }
private:
   // for use only by FHtree
   FHtreeNode( const Object & d,
              FHtreeNode *sb, FHtreeNode *chld, FHtreeNode *prv,
              const FHtreeNode *root )
   :  firstChild(chld), sib(sb), prev(prv), data(d), myRoot(root)
   { }
};



template <class Object>
void FHtree<Object>::display(FHtreeNode<Object> *treeNode, int level) const
{
   if (treeNode == NULL)
      return;

   cout << treeNode->data  << endl;
   display( treeNode->firstChild, level + 1 );
   if (level > 0)
      display( treeNode->sib, level );
}