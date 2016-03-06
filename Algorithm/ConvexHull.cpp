# include<iostream>
# include<math.h>
# include<stdlib.h>
# include<random>
# include<stack>
using namespace std;

class Coordinates {
  public:
    int x;
    int y;
    double polar_angle;

    Coordinates(int x1,int y1,int angle)
    {
        x = x1;
        y = y1;
        polar_angle = angle; 
    }

    Coordinates()
    {
        x = 0;
        y = 0;
        polar_angle = 0.0; 
    }
};

void findPolarAngle(Coordinates obj[],int size) {
    int angle;

    for(int i=0;i<size;i++) {
        if(obj[i].x == 0 && obj[i].y == 0)
            angle = 0;
        else if(obj[i].x > 0 && obj[i].y >= 0)
            angle = atan(obj[i].y/obj[i].x)*180*7/22;
        else if(obj[i].x < 0 && obj[i].y >= 0)
             angle = 180-abs(atan(obj[i].y/obj[i].x)*180*7/22);
        else if(obj[i].x < 0 && obj[i].y <= 0)
            angle = 180 + abs(atan(obj[i].y/obj[i].x)*180*7/22);
        else if(obj[i].x > 0 && obj[i].y <= 0)
            angle = 360 - abs(atan(obj[i].y/obj[i].x)*180*7/22);
        else if(obj[i].x == 0 && obj[i].y > 0)
            angle = 90;
        else if(obj[i].x == 0 && obj[i].y < 0)
            angle = 270;

    obj[i].polar_angle = angle;
    }
}

// void findPolarAngle(Coordinates obj) {
//     int angle;
    
//         if(obj.x == 0 && obj.y == 0)
//             angle = 0;
//         else if(obj.x > 0 && obj.y >= 0)
//             angle = atan(obj.y/obj.x)*180*7/22;
//         else if(obj.x < 0 && obj.y >= 0)
//              cout<<180-abs(atan(obj.y/obj.x)*180*7/22);
//         else if(obj.x < 0 && obj.y <= 0)
//             angle = 180 + atan(obj.y/obj.x)*180*7/22;
//         else if(obj.x > 0 && obj.y <= 0)
//             angle = 360 - abs(atan(obj.y/obj.x)*180*7/22);
//         else if(obj.x == 0 && obj.y > 0)
//             angle = 90;
//         else if(obj.x == 0 && obj.y < 0)
//             angle = 270;

//     obj.polar_angle = angle;

// }

void swap(Coordinates &obj1,Coordinates &obj2) {
    Coordinates temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

void print(Coordinates obj[],int size) {
    for(int i=0;i<size;i++)
        cout<<"("<<obj[i].x<<","<<obj[i].y<<","<<obj[i].polar_angle<<")"<<"\t";
    cout<<"\n";
}   

void insertionSort(Coordinates obj[],int size) {
    for(int i=1;i<size;i++) {
        for(int j=i;j>0;j--) {
            if(obj[j].polar_angle<obj[j-1].polar_angle)
                swap(obj[j],obj[j-1]);
        }
    }
}

int isCounterClockwise(Coordinates c1,Coordinates c2) {   //c1 with lower polar angle and c2 with larger polar angle

    float area = (0.5)*((c1.x*c2.y)-(c2.x*c1.y));

    if(area<=0)
        return false;
    else
        return true;

}

// void findConvexHull(Coordinates obj[],int size) {
    
//     stack<Coordinates> st;

//     st.push(obj[0]);
    
//     for(int i = 1; i<size;i++) {
//         Coordinates abc = st.top();
        
//         if(isCounterClockwise(abc,obj[i]) == true)
//         {

//         }
        
//     }



//     cout<<abc.x;
// }

int main(int argc, char const *argv[])
{
    Coordinates points[10];
    points[0].x = 1;    points[0].y = 22;  points[0].polar_angle = 12;
    points[1].x = 2;    points[1].y = -2;  points[0].polar_angle = 122;  
    points[2].x = 0;    points[2].y = 0;  points[0].polar_angle = 52;
    points[3].x = -2;   points[3].y = 4;  points[0].polar_angle = 22;
    points[4].x = 4;    points[4].y = -4;  points[0].polar_angle = 234;
    points[5].x = -4;   points[5].y = -2;  points[0].polar_angle = 212;
    points[6].x = -19;  points[6].y = 5;  points[0].polar_angle = 44;
    points[7].x = 0;    points[7].y = 23;  points[0].polar_angle = 90;
    points[8].x = 124;  points[8].y = -42;  points[0].polar_angle = 145;
    points[9].x = 12;   points[9].y = 0;  points[0].polar_angle = 190;

    int size = 10;

    findPolarAngle(points,size);
   
    print(points,size);

    insertionSort(points,size);

    print(points,size);
    // Coordinates test1(0,5,45);
    // Coordinates test2(-5,5,50);

    // cout<<isCounterClockwise(test1,test2);

    // findConvexHull(points,size);


    // print(points,size);22
    return 0;
}