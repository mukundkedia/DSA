//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

string FirstNonRepeating(string A){
		    int arr[26]={0};
		    memset(arr,0,sizeof(arr));
		    queue<char> q;
		    string res="";
		    for(int i=0;i<A.size();i++){
		        q.push(A[i]);
		        arr[A[i]-'a']++;
		        while(!q.empty()){
		            if(arr[q.front()-'a']>1){
		                q.pop();
		            }
		            else{
		                break;
		            }
		        }
		        if(q.empty()){
		            res+='#';
		        }
		        else{
		            res+=q.front();
		        }
		    }
	           return res;
		}