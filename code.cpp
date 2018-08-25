#include <bits/stdc++.h>
using namespace std;
time_t now = time(0);

int nodenum=0;

typedef struct tm {
   int tm_sec;   // seconds of minutes from 0 to 61
   int tm_min;   // minutes of hour from 0 to 59
   int tm_hour;  // hours of day from 0 to 24
   int tm_mday;  // day of month from 1 to 31
   int tm_mon;   // month of year from 0 to 11
   int tm_year;  // year since 1900
   int tm_wday;  // days since sunday
   int tm_yday;  // days since January 1st
   int tm_isdst; // hours of daylight savings time
};

typedef struct node
{
    
 tm *timestamp;
 string data;
 int nodenumber;
 string nodeid;
 node *nodeId;
 node *parentId;
 vector<node *>child;
 node *genesisId;
 string hash;
 int val;
}
;
string encryption(string str)
{
    for(i = 0; i<str.length(); i++)
            str[i] = str[i] + 2; 
    return str;
}


string decreption(string str)
{
    for(i = 0; i<str.length(); i++)
            str[i] = str[i] - 2; 
    return str;
}

node *createnode(node * genesis,node *parent, string st)
{
    node * root=new node();
    root->timestamp=localtime(&now);
    root->data=st;
    root->nodenumber=nodenum++;
    root->nodeId=root;
    root->parentId=parent;
    root->genesis=genesis;
    hash<string> hash;
    root->hash=hash(st);
    
    stringstream check1(st);
    string intermediate;
    while(getline(check1, intermediate, ','))
    {
        tokens.push_back(intermediate);
    }
           
    root->val=tokens[2];         
    if(parent==NULL)
    {
        return node;
    }
    else
    {
        parent->child.push_back(root);
        return NULL;
    }
}

node *find(node *genesis,string str)
{
    if(genesis==NULL)
    reurn NULL;
     queue<Node *>q;
   q.push(root);
 
   while (!q.empty())
   {
        
         Node * pl = q.front();
         q.pop();
         if(!pl->data.compare(str))
         return pl;
         for (int i=0; i<pl->child.size(); i++)
         q.push(pl->child[i]);
    }
    return NULL;
}


void owner_info(node* pl)
{
    int i;
    cout<<"1. change Value"<<endl;
    cout<<"2. Change ownership"<<endl;
    cout<<"3. display info"<<endl;
    cin>>i;
    switch(i);
    case 1:
            cout<<"enter the new value";
            int val;
            cin>>val;
        vector <string> tokens;
        stringstream check1(pl->data);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        tokens[2]=val;
        string sk= tokens[0]+tokens[1]+tokens[2];
        pl->data=sk;
        hash<string> hash;
        root->hash=hash(st);
        break;
        
        
    case 2:
    
        cout<<" enter the new owner id, owner name";
        string stl1;
        string stl2;
        cin>>stl1;
        cin>>stl2;
        vector <string> tokens;
        stringstream check1(pl->data);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        tokens[1]=stl2;
        tokens[0]=stl1;
        string sk= tokens[0]+tokens[1]+tokens[2];
        pl->data=sk;
        hash<string> hash;
        root->hash=hash(st);
        break;
        
    case 3:
        vector <string> tokens;
        stringstream check1(pl->data);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        for(int i=0;i<n;i++)
        cout<<tokens[i]<<endl;
        break;
    }
    

int  findlongestchain(node *ptr)
{
    if (!ptr)
        return 0;
 
    
    int maxdepth = 0;
    for (vector<Node*>::iterator it = ptr->child.begin();
                              it != ptr->child.end(); it++)
        maxdepth = max(maxdepth, depthOfTree(*it));
 
    return maxdepth + 1 ;
}

void merge(node *n1, node *n2)
{
    
    if(findlongestchain(n1)>=findlongestchain(n1))
    {	
	n1->val+=n2->val;
	for(int i=0;i<n2->child.size();i++)
        {
		n1->child.push_back(n2.child[i]);
	}
        for(int i=0;i<n2->parentId->child.size();i++)
        {
            if(n2->parentId->child[i]==n2)
            {
                n2->parentId->child[i]=NULL;
		break;
            }
        }
		vector <string> tokens;
        	stringstream check1(n1->data);
       		 string intermediate;
        	while(getline(check1, intermediate, ','))
        	{
            		tokens.push_back(intermediate);
        	}
		tokens[2]=n1->val;
		n2->data=tokens[0]+tokens[1]+tokens[2];	
    }
	else
	{
		n2->val+=n1->val; 	
		for(int i=0;i<n1->child.size();i++)
        	{
			n2->child.push_back(n1.child[i]);
		}
		for(int i=0;i<n1->parentId->child.size();i++)
        	{
            		if(n1->parentId->child[i]==n1)
            		{
                		n1->parentId->child[i]=NULL;
				break;
            		}
        	}
		vector <string> tokens;
        	stringstream check1(n2->data);
       		 string intermediate;
        	while(getline(check1, intermediate, ','))
        	{
            		tokens.push_back(intermediate);
        	}
		tokens[2]=n2->val;
		n2->data=tokens[0]+tokens[1]+tokens[2];
        
	}
}


int main() {
	node *genesis=NULL;
	int c;
	cout<<"1. Create Genesis";
	cout<<"2. Create child Nodes of some node";
	cout<<"3. Create one child node of Particular node";
    cout<<"4. owner info";
    cout<<"5. Find longest chain of Genesis node";
    cout<<"6. Find longest chain from particular node";
    cout<<"7. Mearge two nodes"
    
    switch(c)
    
    case 1:cout<<"enter the owner id, owner name , value"<<endl;
                        string st;
                        cin>> st;
                        encrypt(st);
                        genesis=createNode(genesis,NULL,st);
                        
    case 2: if(genesis!=NULL)
            {
                printf("enter parent node owner id,owner name, value \n");
                string s;
                cin<<s;
                node* par=find(decrypt(string));
                if(par!=NULL)
                {
                    cout<<"enter no of child u want to enter"<<endl;
                    int no_of_child;
                    cin>>no_of_child;
                    while(no_of_child>0)
                    {
                         
                        
                        cout<<"enter the owner id, owner name , value"<<endl;
                        string st;
                        cin>> st;
                        stringstream check1(pl->st);
                        string intermediate;
                        while(getline(check1, intermediate, ','))
                        {
                            tokens.push_back(intermediate);
                        }
                        int sum=0;
                        for(int i=0;i<par->child.size();i++)
                        {
                            sum+=par->child[i]->val;
                        }
                        sum-=par->val;
                        if(sum>0)
                        {
                            encrypt(st);
                            createNode(genesis,par,st);
                            no_of_child--;
                        }
                        else
                        {
                            cout<<"val mach greater cant be inserted";
                        }
                    }
                }
                else 
                {
                    cout<<"invalid  owner_id,name,value";
                }
            }
            else
            {
                cout<<"Create gensis first"<<endl;
                        
            }
            break;
    case 3: if(genesis!=NULL)
            {
                printf("enter parent node owner id,owner name,value \n");
                string s;
                cin>>s;
                node* par=find(genesis,decrypt(string));
                if(par!=NULL)
                {
                        cout<<"enter the owner id, owner name , value"<<endl;
                        string st;
                        cin>> st;
                       stringstream check1(pl->st);
                        string intermediate;
                        while(getline(check1, intermediate, ','))
                        {
                            tokens.push_back(intermediate);
                        }
                        int sum=0;
                        for(int i=0;i<par->child.size();i++)
                        {
                            sum+=par->child[i]->val;
                        }
                        sum-=par->val;
                        if(sum>0)
                        {
                            encrypt(st);
                            createNode(genesis,par,st);
                            no_of_child--;
                        }
                        else
                        {
                            cout<<"val mach greater cant be inserted";
                        }
                }
                else 
                {
                    cout<<"invalid  owner_id,name,value"<<endl;
                }
            }
            else
            {
                cout<<"create genesis first"<<endl;
            }
            break;
            
    case 4:
                printf("enter parent node owner id,owner name, value\n");
                string s;
                cin>>s;
                node* par=find(genesis,decrypt(string));
                if(par!=NULL)
                {
                    owner_info(par);
                }
                else
                {
                    cout<<"owner not found"<<endl;
                }
                break;
                
    case 5:cout<<findlongestchain(genesis);break;
    case 6:cout<<"enter the owner id, owner name , value"<<endl;
            string sl;
            cin>>sl;
            node* n=find(genesis,decrypt(string));
            cout>>findlongestchain(n);break;
    case 7:cout<<"enter the owner id, owner name , value of first node"<<endl;
            string s1;
            cin>>s1;
            cout<<"enter the owner id, owner name , value of second node"<<endl;
            string s2;
            cin>>s2;
            node * p1=(find(decrypt(s1)));
            node * p2=(find(decrypt(s2)));
            if(p1!=NULL && p2!=NULL)
            {
                merge(p1,p2);
                cout<<"mearged"<<endl;
            }
	return 0;
}
