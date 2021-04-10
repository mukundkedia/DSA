//https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long mod = 1000000007;
    long long n1=0,n2=0;
  while(l1){
      n1=(n1*10+l1->data)%mod;
      l1=l1->next;
  }
  while(l2){
      n2=(n2*10+l2->data)%mod;
      l2=l2->next;
  }
  return ((n1%mod)*(n2%mod))%mod;
}