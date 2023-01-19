
template<class TYPE, class KTYPE>
class AVLTreeExt: public AvlTree<TYPE, KTYPE> {
	//Added by Dongmo
	void _traversal_preorder(void (*process)(TYPE dataproc), NODE<TYPE> *root) {
		if (root) {
			process(root->data);
			_traversal_preorder(process, root->left);
			_traversal_preorder(process, root->right);
		}
		return;
	}
    /*void TotalWord(DATA ss){
        // AvlTree<DATA, string> tree;
        totalWords += ss.info;
        //tree.AVL_Traverse(TotalWord);
        if(totalWords != 0 ){
            cout << "Total words in dictionary is " << totalWords << endl;
        }
        //return totalWords;
    } */

public:
	//Added by Dongmo
	void AVL_Traverse_preorder(void (*process)(TYPE dataProc)) {
		_traversal_preorder(process, AvlTree<TYPE, KTYPE>::tree);
		return;
	}
	void AVL_TotalWord(){
        TotalWord(AvlTree<TYPE, KTYPE>::tree);
	}

};
