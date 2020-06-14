#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>

#define pow_2(n) (1 << n)
#define INF 0x3f3f3f3f
using namespace std;

struct node{
	struct node* left = NULL;
	struct node* right = NULL;
	struct node* pred = NULL;
	struct node* succ = NULL;
	int key, priority, subtree, num;
	
	node(int key){
		this->priority = rand();
		this->key = key;
		this->subtree = 1;
    this->num = 1;
	}
	
	node(){
		this->priority = rand();
		this->subtree = 1;
	}
};


class treap{
	int size;
	struct node* root;
	struct node* begin;
	struct node* last;
	struct node* T_nil;
	
	private: 
		
		void reset(){
			begin = root; last = root;
			while(begin->left != NULL) begin = begin->left;
			while(last->right != NULL) last = last->right; 
			begin->pred = T_nil, last->succ = T_nil;
			T_nil->pred = last, T_nil->succ = begin;
		}
		
		void inorder(struct node* x){
			if(x == NULL) return;
			inorder(x->left);
			printf("(%d, %d, %d %d)\n", x->key, x->priority, x->subtree, x->num);
			inorder(x->right);
		}
		
		void preorder(struct node* x){
			if(x == NULL) return;
			printf("(%d, %d, %d %d)\n", x->key, x->priority, x->subtree, x->num);
			preorder(x->left);
			preorder(x->right);
		}
		
		void postorder(struct node* x){
			if(x == NULL) return;
			postorder(x->left);
			postorder(x->right);
			printf("(%d, %d, %d %d)\n", x->key, x->priority, x->subtree, x->num);
		}
		
		void heapify(struct node* start){
			start->priority = INF;
			while(!(start->left == NULL && start->right == NULL)){
				start->subtree--;
				if(start->left == NULL){
					rotate_left(start);
				}else if(start->right == NULL){
					rotate_right(start);
				}else{
					if(start->left->priority < start->right->priority){
						rotate_right(start);
					}else{
						rotate_left(start);
					}
				}
			}
			
		}
		
		void rotate_left(struct node* x){
			struct node* y = x->right;
			x->right = y->left;
			
			int y_r = (y->right == NULL) ? 0:y->right->subtree;
			int x_l = (x->left == NULL) ? 0:x->left->subtree;
			int x_r = (x->right == NULL) ? 0:x->right->subtree;
			
			x->subtree += x_l + x_r;
			y->subtree += x->subtree + y_r;
			
			y->left = x;
		}
		
		void rotate_right(struct node* x){
			struct node* y = x->left;
			x->left = y->right;
			
			int y_l = (y->left == NULL) ? 0:y->left->subtree;
			int x_l = (x->left == NULL) ? 0:x->left->subtree;
			int x_r = (x->right == NULL) ? 0:x->right->subtree;
			
			x->subtree += x_l + x_r;
			y->subtree += x->subtree + y_l;
			
			
			y->right = x;
		}
		
		
		struct node* make_new_node(struct node* par, int key){
			if(key == par->key){
        par->num++;
        this->size++;
        return NULL;
      }

      struct node* cur = new node(key);
			
	    if(key < par->key){
				cur->succ = par;
				cur->pred = par->pred;
			}else{
				cur->pred = par;
				cur->succ = par->succ;
			}
			
			cur->pred->succ = cur;
			cur->succ->pred = cur;
			reset();		
			this->size++;
			return cur;
		}
		
		void add(struct node* cur, int key){
			cur->subtree++;
			if(key < cur-> key){
				if(cur->left == NULL){
					cur->left = make_new_node(cur, key);
				}else{
					add(cur->left, key);
				}
				
				if(cur->left->priority < cur->priority)
					this->rotate_right(cur);
			}else if(key > cur-> key){
				if(cur->right == NULL){
					cur->right = make_new_node(cur, key);
				}else{
					add(cur->right, key);
				}
				
				if(cur->right->priority < cur->priority)
					this->rotate_left(cur);
			}else{
        make_new_node(cur, key);
      }
		}
		
    
		
	public:
		treap(){
			this->size = 0;
			this->root = NULL;
			this->begin = NULL;
			this->last = NULL;
			
			this->T_nil = new node();
		}
		
		struct node * find(int key){
			struct node* start = root;
			struct node* y = root;

      while(start != NULL && key != start->key){
        y = start;
        if(key < start->key)
          start = start->left;
        else
          start = start->right;
      }
      
      if(start != NULL) return start;
      else return (key < y->key) ? y : y->pred;
		}
		
		void insert(int key){
			if(size){
				add(root, key);
			}else{
				this->root = new node(key);
				root->pred = T_nil;
				root->succ = T_nil;
				T_nil->pred = root;
				T_nil->succ = root;
				size++;
				reset();
			}
		}
		
		void erase(int key){
			struct node* x = find(key);
			if(x == T_nil || x->key != key) return;

      if(x->num > 1){
        x->num--;
        x->subtree--;
        return;
      }

			heapify(x);
			size--;
			x->pred->succ = x->succ;
			x->succ->pred = x->pred;
			assert(x->left == NULL && x->right == NULL);
			delete x;
	  	x = new node();
      reset();

		}
		
    int get_index(int key){
      struct node* x = root;
      int total = 0;
      while(x != NULL){
        bool L = (x->left == NULL) ? true:false, R = (x->right == NULL) ? true:false;
        if((L&&R)) break;
        if(x->key > key){
           total += (L) ? 0:x->left->subtree;
           total += x->num;
           x = x->right;
        }else if(x->key == key){
          total += (L) ? 0:x->left->subtree;
          return total + x->num;
        }else{
          x = x->left;
        }
      }
      return -1;
    }

    int get_key(int index){
      struct node* x = root;
      int total = 0;
      while(true){
        if(total + ((x->left == NULL) ? 0:x->left->subtree) < index){
          total += (x->left == NULL) ? 0:x->left->subtree;
          if(total + x->num < index){
            total += x->num;
            x = x->right;
          }else{
            return x->key;
          }
        }else{
          x = x->left;
        }
      }

      return this->last->key;
    }

		void print(){
			inorder(root);
		}
		
		void print_all(){
			puts("preorder");
			preorder(root);
			puts("inorder");
			inorder(root);
			puts("postorder");
			postorder(root);
		}
			
};



int main(){
	srand(time(0));
	
	treap t = treap();
	
	int com;
  int T;
  scanf("%d", &T);

	while(T--){
    scanf("%d", &com);
		if(com == -1) break;
		else if(com == 1){
			scanf("%d", &com);
			t.insert(com);
		}else if(com == 2){
		  scanf("%d", &com);
			t.erase(com);
		}else if(com == 3){
			scanf("%d", &com);
      printf("%d\n", t.get_index(com));
		}else if(com == 4){
      scanf("%d", &com);
      printf("%d\n", (t.get_key(com)));
    }else if(com == 5){
      scanf("%d", &com);
      printf("%d\n", ((t.find(com))->key == com) ? t.find(com)->pred->key : t.find(com)->pred->key);
    }else if(com == 6){
      scanf("%d", &com);
      printf("%d\n", ((t.find(com))->key == com) ? t.find(com)->succ->key : t.find(com)->key);
    }else if(com == 7){
      t.print_all();
    }
	}
	
	
	
	
	return 0;
}

