#include <stdio.h>
#include <math.h>
typedef struct{
    float x;
    float y;
}point;
float dis();
void distance();
void input_points();
void area_tri();
void area_quad();
void mid_p();
void slope();
void is_colli();
void dist_line();
void equ();
void is_parallel();
void Co_ordination();
void Co_ordination_explain(){
    printf("You can use the following functions:\n");
    printf("Distance: 1\n");
    printf("Area of triangle(using co-ordinates of triangle): 2\n");
    printf("Area of quadrilateral(using co-ordinates of quadrilateral): 3\n");
    printf("Midpoint between two points: 4\n");
    printf("Slope of line: 5\n");
    printf("Checking collinearity: 6\n");
    printf("Distance of a point from line: 7\n");
    printf("Finding equation of line(from 2 points): 8\n");
    printf("Checking for parallel lines: 9\n\n");
    Co_ordination();
}
void Co_ordination(){
    int c;
    printf("Enter the operation: ");
    scanf("%d",&c);
    switch(c){
        case 1:
            distance();
            break;
        case 2:
            area_tri();
            break;
        case 3:
            area_quad();
            break;
        case 4:
            mid_p();
            break;
        case 5:
            slope();
            break;
        case 6:
            is_colli();
            break;
        case 7:
            dist_line();
            break;
        case 8:
            equ();
            break;
        case 9:
            is_parallel();
            break;
        default:
            printf("Enter the correct number\n");
            Co_ordination();
            break;
    }
}
void input_points(point *p,int n){
    printf("Enter the x and y co-ordinates of point %d: ",n);
    scanf("%f %f",&p->x,&p->y);
}
float dis(point p1,point p2){
    return pow((pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2)),0.5);
}
void distance(){
    point p1,p2;
    input_points(&p1,1);
    input_points(&p2,2);
    printf("Distance between 2 points is: %f",dis(p1,p2));
}
void area_tri(){
    point p1,p2,p3;
    input_points(&p1,1);
    input_points(&p2,2);
    input_points(&p3,3);
    float a,b,c,s,area;
    a=dis(p1,p2);
    b=dis(p2,p3);
    c=dis(p3,p1);
    s=(a+b+c)/2;
    area=pow((s*(s-a)*(s-b)*(s-c)),0.5);
    printf("Area of triangle is %f",area);
}
void area_quad(){
    point p1,p2,p3,p4;
    input_points(&p1,1);
    input_points(&p2,2);
    input_points(&p3,3);
    input_points(&p4,4);
    float a,b,c,d,e,s1,s2,area;
    a=dis(p1,p2);
    b=dis(p2,p3);
    c=dis(p3,p4);
    d=dis(p4,p1);
    e=dis(p3,p1);
    s1=(a+b+e)/2;
    s2=(c+d+e)/2;
    area= pow((s1*(s1-a)*(s1-b)*(s1-e)),0.5) + pow((s2*(s2-c)*(s2-d)*(s2-e)),0.5);
    printf("Area of quadrilateral is %f",area);
}
void mid_p(){
    point p1,p2,p3;
    input_points(&p1,1);
    input_points(&p2,2);
    p3.x=(p1.x+p2.x)/2;
    p3.y=(p1.y+p2.y)/2;
    printf("The mid point is (%f,%f)",p3.x,p3.y);
}
void slope(){
    point p1,p2;
    input_points(&p1,1);
    input_points(&p2,2);
    float sl=(p2.y-p1.y)/(p2.x-p1.x);
    printf("Slope is %f",sl);
}
void is_colli(){
    point p1,p2,p3;
    input_points(&p1,1);
    input_points(&p2,2);
    input_points(&p3,3);
    float a,b;
    a=(p2.y-p1.y)/(p2.x-p1.x);
    b=(p3.y-p2.y)/(p3.x-p2.x);
    if(a==b){
        printf("Three points are collinear");
    }
    else{
        printf("Three points are not collinear");
    }
}
void dist_line(){
    point p1;
    input_points(&p1,1);
    float a,b,c;
    printf("Enter the equation of line in ax+by+c=0 format: ");
    scanf("%fx+%fy+%f=0",&a,&b,&c);
    float dist_l;
    dist_l=(a*p1.x+b*p1.y+c)/(pow((a*a+b*b),0.5));
    printf("Distance between point and line is %f",dist_l);
}
void equ(){
    point p1,p2;
    input_points(&p1,1);
    input_points(&p2,2);
    //General form of equation -  (y-y1)=m*(x-x1)  where m is slope of line
    //So equation is -  m*x-y+(y1-m*x1)=0 
    float m=(p2.y-p1.y)/(p2.x-p1.x);
    printf("The equation of line is - %fx+%fy+%f=0",m,-1,p1.y-m*p1.x);
}
void is_parallel(){
    point p1,p2,p3,p4;
    printf("Enter the first set of points: \n");
    input_points(&p1,1);
    input_points(&p2,2);
    printf("Enter the second set of points: \n");
    input_points(&p3,1);
    input_points(&p4,2);
    float m1,m2;
    m1=(p2.y-p1.y)/(p2.x-p1.x);
    m2=(p4.y-p3.y)/(p4.x-p3.x);
    if(m1==m2){
        printf("Parallel");
    }
    else{
        printf("Not parallel");
    }
}