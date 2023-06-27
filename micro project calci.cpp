#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define clr system("cls")
using namespace std;
int main() 
{	int op,a,b;
    float first, second;
start:
	cout <<"\nEnter an operation to perform ";
	cout <<"\n1. Addition";
	cout <<"\n2. Subtraction ";
	cout <<"\n3. Multiplication";
	cout <<"\n4. Division";
	cout <<"\n5. percentage";
	cout <<"\n6. Square root";
	cout <<"\n7. Modulus";
	cout <<"\n8. factorial";
	cout <<"\n9. Power";
	cout <<"\n10.Reciprocal";
	cout <<"\n11.Sine";
	cout <<"\n12.Cosine";
	cout <<"\n13.Tangent";
	cout <<"\n14.Sine Inverse";
	cout <<"\n15.Cosine Inverse";
	cout <<"\n16.Tangent Inverse";
	cout <<"\n17.Logarithm base 10";
	cout <<"\n18.Antilog (10 to power x)";
	cout <<"\n19.Ln (Natural Logarithm)";
	cout <<"\n20.Antilog (e to power x)";
	cout <<"\nEnter 0 to exit";
	cout <<"\n";
	cin >> op;
	if(op!=0)
	cout <<"Selected operator is "<<op;
	switch(op)
	{   case 0:
			goto y;
		case 1:
  	  		cout <<"\nEnter two numbers for addition";
  	  		cin >> first >> second;
      		cout <<"\n"<<first<<" + "<<second<<" = "<< first + second;
      		break;
    	case 2:
      		cout <<"\nEnter two numbers for subtraction";
  	  		cin >> first >> second;
      		cout <<"\n"<<first<< "-" <<second<< "=" <<first - second;
      		break;
    	case 3:
      		cout <<"\nEnter two numbers for multiplication";
  	  		cin >> first >> second;	
      		cout <<"\n"<<first<<" * "<<second<<" = "<<first*second;
      		break;
    	case 4:
      		cout <<"\nEnter two numbers for division";
  	  		cin >> first >> second;
			if(second==0)	
			{	cout <<"Division by 0 (Zero) is not allowed";
				break;
			}
      		cout <<"\n"<<first<<" / "<<second<<" = "<< first / second;
      		break;
    	case 5:
      		cout <<"\nEnter two numbers for obtaining percentage";
  	  		cin >> first >> second;
      		cout <<"\n"<<first<< "out of" <<second<<" = "<<((first / second) * 100)<< "percent";
      		break;
    	case 6:
      		cout <<"\nEnter a number for obtaining square root";
  	  		cin >> first;
      		cout <<"\nsquare root of"<<first<<" is "<<sqrt(first);
      		break;
		case 7:
      		cout <<"\nEnter two numbers for modulo division";
  	  		cin >> first >> second;
      		cout <<"\nremainder of"<<(int)first<<"/" <<(int)second<<" = "<<(int)first % (int)second;
      		break;
    	case 8:
      		cout <<"\nEnter a number for counting factorial";
	  		cin >> a;
	  		if(a<=0)	
      		{	cout <<"\nfactorial is not possible for numbers  less than one."; 
      			break;
  			}
  			else
  			{	int fact=1;
  				b=a;
  				while(b>1)
  				{	fact=fact*b;
					b--;
				}
				cout <<"\n"<<a<<"! = "<<fact;
			}
			break;
		case 9:
      		cout <<"\nEnter two numbers a and b to count a^b";
	  		cin >> a >> b;
	  		first=pow(a,b);
  			cout <<"\n"<<a<<" Power "<<b<< "= "<<first;
			break;
		case 10:
      		cout <<"\nEnter a number to find reciprocal";
	  		cin >> first;
	  		if(first==0)
	  		{	cout <<"\nReciprocal is not possible for 0(Zero)."; 
      			break;
			}
	  		second=1/first;
  			cout <<"1/"<<first<<" = "<<second;
			break;
		case 11:
      		cout <<"\nEnter an angle (in degrees) to Sine";
	  		cin >> first;
	  		second=sin((first*3.141592/180));
  			cout <<"Sin("<<first<<")= "<<second;
			break;
		case 12:
      		cout <<"\nEnter an angle (in degrees) to Cosine";
	  		cin >> first;
	  		second=cos((first*3.141592/180));
  			cout <<"Cos("<<first<<")="<<second;
			break;
		case 13:
      		cout <<"\nEnter an angle (in degrees) to Tangent";
	  		cin >> first;
	  		second=tan((first*3.141592/180));
  			cout <<"Tan("<<first<<")=" <<second;
			break;
	    case 14:
      		cout <<"\nEnter a value to find its Inverse Sine";
	  		cin >> first;
	  		if(first>1.0 || first <-1.0)
	  		{	cout <<"Entered value is not in the domain of Sine Function";
	  			break;
			}
	  		second=asin(first);
  			cout <<"Inverse Sin("<<first<<")= " << second*180/3.141592<<"degrees or" <<second<<"radians";
			break;		
	    case 15:
      		cout <<"\nEnter a value to find its Inverse Cosine";
	  		cin >>first;
	  		if(first>1.0 || first <-1.0)
	  		{	cout <<"Entered value is not in the domain of Cosine Function";
	  			break;
	  		}
			second=acos(first);
  			cout <<"Inverse Cos("<<first<<")= " <<second*180/3.141592<<" degrees or"<<second<<"radians";
			break;
		case 16:
      		cout <<"\nEnter a value to find its Inverse Tangent";
	  		cin >> first;
	  		second=atan(first);
  			cout <<"Inverse Tan("<<first<<")="<<second*180/3.141592<<"degrees or"<<second<< "radians";
			break;		
		case 17:
      		cout <<"\nEnter a value to find its logarithm base 10";
	  		cin >> first;
	  		if(first<=0)
	  		{	cout <<"Logarithm is not defined for the Entered value";
	  			break;
	  		}
	  		second=log10(first);
  			cout <<"log("<<first<<")="<<second;
			break;	
		case 18:
      		cout <<"\nEnter a value to find its AntiLogarithm";
	  		cin >> first;
	  		second=pow(10,first);
  			cout <<"Antilog: 10 to power ("<<first<<")="<<second;
			break;			
		case 19:
      		cout <<"\nEnter a value to find its natural logarithm (base e)";
	  		cin >>first;
	  		if(first<=0)
	  		{	cout <<"Natural Logarithm is not defined for the Entered value";
	  			break;
	  		}
	  		second=log(first);
  			cout <<"ln("<<first<<")="<<second;
			break;	
		case 20:
      		cout <<"\nEnter a value to find its AntiLogarithm (base e))";
	  		cin >>first;
	  		second=pow(M_E,first);
  			cout <<"Antilog: e to power("<<first<<")= "<<second;
			break;
		default:
			cout <<"Error, invalid operator entered";
			cout <<"Enter a valid operator";
			break;
	}
	cout <<"\nHere is your answer... \nPress any key to continue";
	getch();
	clr;
	goto start;
y: 	clr;
	cout <<"\nThank you for using our Calculator--\n\t\t\t\t Group-2";


}
