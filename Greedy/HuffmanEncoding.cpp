// /https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

struct Node{
	        char data;
	        int freq;
	        Node *left,*right;
	        Node(char data,int freq){
	            this->data=data;
	            this->freq=freq;
	            left=right=NULL;
	        }
	    };
	    
	    struct compare {
 
    bool operator()(Node* l, Node* r)
 
    {
        return (l->freq > r->freq);
    }
};
	    

	    
	    void solve(Node* top,vector<string> &res,string s){
	        if(top->data!='#'){
	            res.push_back(s);
	            return;
	        }
	        solve(top->left,res,s+"0");
	        solve(top->right,res,s+"1");
	        return;
	    }
	    
	    vector<string> Huffman(string s, vector<int> f,int N){
	        Node *first,*second,*top;
	        priority_queue<Node*,vector<Node*>,compare> minHeap;
	        for(int i=0;i<N;i++){
	            minHeap.push(new Node(s[i],f[i]));
	        }
	        while(minHeap.size()!=1){
	            first = minHeap.top();
	            minHeap.pop();
	            second = minHeap.top();
	            minHeap.pop();
	            top = new Node('#',first->freq+second->freq);
	            top->left = first;
	            top->right=second;
	            minHeap.push(top);
	        }
	        vector<string> res;
	        string s1="";
	        solve(top,res,s1);
	        return res;
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		   return Huffman(S,f,N);
		}