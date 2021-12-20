// *************************************************************
//   Find intersecting Point of two Lines in Three Dimensions.
// *************************************************************

#include <iostream>
using namespace std;

class Line
{
    public:
    float coord1[3],coord2[3],dr[3];
    
    void userInput(int no)
    {
        cout<<"Coordinates of line "<<no<<endl;
        cout<<"Enter 1st Coordinate Of Line : \n";
        for(int i=0;i<3;i++)
        {
            cin>>coord1[i];           // Taking Input form user for First Coordinate of line
        }

        cout<<"Enter 2nd Coordinate Of Line : \n";
        for(int i=0;i<3;i++)
        {
            cin>>coord2[i];            // Taking Input form user for Second Coordinate of line
        }

        directionRatio();
    }

    void directionRatio()
    {
        for(int i=0;i<3;i++)
        {
            dr[i]=coord2[i]-coord1[i];      // Computing Direction Ratios of Line
        }
    }

    void coOrd1()
    {
        cout<<"Coordinates of line : [";
        for(int i=0;i<3;i++)
        {
            cout<<coord1[i]<<",";       // Display First Coordinate of line
        }
        cout<<"]"<<endl;
    }

    void coOrd2()
    {
        cout<<"Coordinates of line : [";
        for(int i=0;i<3;i++)
        {
            cout<<coord2[i]<<",";         // Display Second Coordinate of line
        }
        cout<<"]"<<endl;
    }
};

class Matrix2D
{
    float mat[3][3];

    public:
    Matrix2D(Line l1 , Line l2 )     // Line Equation in Matrix form
    {
        mat[0][0]=l1.dr[0];  
        mat[0][1]=-l2.dr[0];
        mat[0][2]= l2.coord1[0]-l1.coord1[0];

        mat[1][0]=l1.dr[1];  
        mat[1][1]=-l2.dr[1]; 
        mat[1][2]= l2.coord1[1]-l1.coord1[1];

        mat[2][0]=l1.dr[2];  
        mat[2][1]=-l2.dr[2]; 
        mat[2][2]= l2.coord1[2]-l1.coord1[2];
    }
    
    float determinant(int sr , int er , int sc,int ec)
    {
        float t[2][2];
        
        t[0][0]=mat[sr][sc];             // Storing Value in 2 X 2 Matrix
        t[0][1]=mat[sr][ec];
        t[1][0]=mat[er][sc];
        t[1][1]=mat[er][ec];
        
        float det;
        det = t[0][0]*t[1][1] - t[1][0]*t[0][1];  // Calculating Determinant
        return det;
    }

    float D()                        // Determinant Function
    {    
        int D;
        D = determinant(0,1,0,1);
        if(D != 0)
           {
               return determinant(0,1,0,1);
           }
        else
           { 
              return determinant(0,2,0,1);
           }
    }

    float Dx()                    // Calculating Dx 
    {
        int D;
        D = determinant(0,1,0,1);
        if(D != 0)
           {
               return determinant(0,1,2,1);
           }
        else
           { 
              return determinant(0,2,2,1);
           }
    }

    float Dy()                  // Calculating Dy 
    {
        int D;
        D = determinant(0,1,0,1);
        if(D != 0)
           {
               return determinant(0,1,0,2);
           }
        else
           { 
              return determinant(0,2,0,2);
           }
    }
};

class Intersect
{
    public:
    Intersect(Line l1 ,Line l2 , Matrix2D md)
      { 
        if(((((l1.dr[0])*(-l2.dr[1]))-((l1.dr[1])*(-l2.dr[0])))!=0) || ((((l1.dr[0])*(-l2.dr[2]))-((l1.dr[2])*(-l2.dr[0])))!=0))  // Condition for Intersection of Two Lines.   
           {
             cout<<"Given Two Lines Intersects in 3D and Intersecting Point is :  \n";
             cout<<"x : "<<l1.coord1[0]+((l1.dr[0])*(float)(md.Dx()/md.D()))<<endl;       // Calculate and Display intersection point of Two Lines
             cout<<"y : "<<l1.coord1[1]+((l1.dr[1])*(float)(md.Dx()/md.D()))<<endl;
             cout<<"z : "<<l1.coord1[2]+((l1.dr[2])*(float)(md.Dx()/md.D()))<<endl;
           }
        else 
           {
               cout<<"Given Two Lines Do Not Intersect in 3D \n";
           }   
      }
};

int main()
{
    Line l[2];      // To Create Line equation by two pint form.
    for(int i=0;i<2;i++)
    {
        l[i].userInput(i+1);     // Accept abscissa , ordinate & applicate from User.
    }
    Matrix2D m(l[0],l[1]);       // To Calculate Determinant of 2D Matrices. 
    Intersect i(l[0],l[1],m);    // To  find Lines Intersect  each other or not. if intersect then Display the intersecting point.  
    return 0;
}