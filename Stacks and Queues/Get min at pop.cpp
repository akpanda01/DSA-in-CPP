stack<int> _push(int arr[],int n)
{
   stack<int>s;
   
   for(int i=0;i<n;i++){
       if(s.empty()){
           s.push(arr[i]);
       }else{
           s.push(min(arr[i],s.top()));
       }
   }
   return s;
}

void _getMinAtPop(stack<int>s)
{
    // your code here
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
