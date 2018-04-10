#include<iostream>
#include<conio.h>
#include<process.h>
#include <stdlib.h>
using namespace std;
class north
{
   public:
      int c[10][10],s1[10],d1[10],s[10],d[10];
      int m,n,i,j,sum1,sum2;
      void getdata();
      void cal();
};
void north::getdata(void)
{
     //input for dimensions
	cout<<"enter number of row (m) : - ";
	cin>>m;
	cout<<"enter number of column (n) : - ";
	cin>>n;
    //input for cost matrix
	cout<<"ENTER THE COST MATRIX"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		      cout<<endl<<"enter element of row ";
		      cout<<i+1<<" and column "<<j+1<<" : - ";
		      cin>>c[i][j];
		}
	}
    //input for supply
	cout<<endl<<"ENTER THE SUPPLY ARRAY"<<endl;
       int	sum1=0;
	for(j=0;j<m;j++)
	     {
		cin>>s[j];
		s1[j]=s[j];
		sum1=sum1+s1[j];
	     }
		cout<<"supply=>"<<sum1;


    //input for demand
	cout<<endl<<"ENTER THE DEMAND ARRAY"<<endl;
      int	sum2=0;
	for(j=0;j<n;j++)
	      {
		cin>>d[j];
		d1[j]=d[j];
		 sum2=sum2+d1[j];
		}
		   cout<<"demand=>"<<sum2;
		   if(sum1!=sum2)
		{
		    cout<<"\nsupply=>"<<sum1;
		    cout<<"\ndemand=>"<<sum2;
			cout<<"\nProblem is unbalanced";
			exit(0);
		}

}
void north::cal(void)
{

	       //	exit;
		i=0;j=0;
		int sum=0;
		start:   if(i==m&&j==n)
                    goto end;
			     else if (s[i]==d[j])
			     {
				     sum=sum+(c[i][j]*s[i]);
				     i++;j++;
			     }
			     else if(s[i]<d[j])
			     {
					d[j]=d[j]-s[i];
					sum=sum+(c[i][j]*s[i]);
					     i++;
			     }
			     else if(s[i]>d[j])
			     {
					s[i]=s[i]-d[j];
					sum=sum+(c[i][j]*d[j]);
					j++;
			     }
			     goto start;
		end:

		    cout<<endl<<"-------------- ---------------------------------"<<endl;
		    cout<<"|								|"<<endl;
		    for(i=0;i<m;i++)
		    {
			 cout<<"|	";
			 for(j=0;j<n;j++)
			 {
			      cout<<c[i][j]<<"	";
			 }
			 cout<<"|	"<<s1[i]<<endl<<"|				|";
			 cout<<endl<<"|				|"<<endl;
		    }
			  cout<<" ------------------------------------------------"<<endl<<endl;
		    for(i=0;i<n;i++)
		    {
		       cout<<"	"<<d1[i];
		    }
		    cout<<"\nTHE MINIMUM TRANSPORTATION COST = "<<sum<<" units";
}
int main()
{
   north n;
   n.getdata();
   n.cal();
   return 0;
}
