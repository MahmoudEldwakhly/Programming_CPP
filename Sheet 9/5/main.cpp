#include<iostream>
#include<cstring>

using namespace std ;




int GetValues(char* Text, double* Values)
{
int nValues = 0;
char*c ;   // Pointer char c ;
c = strtok (Text , " ") ;    // strtok (Text , ", / ' ")
while(c!=NULL)
{
    Values [nValues] = atof (c) ;    // Function array to float

    c = strtok (NULL , " ") ;       // NULL = 0
    nValues ++ ;
}
return nValues ;
}


int main()
{
char Text[] = "7672.28 276763.22 0.767 1.2878 772.2 1878 152 0.0123";
double Values[100];
int nValues;
nValues = GetValues(Text, Values);

for(int i=0;i<nValues;i++)
cout<<i+1<<" : "<<Values[i]<<endl;
}
