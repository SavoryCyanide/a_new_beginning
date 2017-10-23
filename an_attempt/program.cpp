#include <iostream>
#include <ctime>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

//Prototypes
void picSaver(Mat pic);

//Main
int main(int argc, char** argv) {
    VideoCapture cap;

    if(!cap.open(0))
        return 0;

    for(;;)
    {
          Mat frame;
          cap >> frame;
          if( frame.empty() ) 
              break;

          imshow("Window", frame);

          if( waitKey(1) == 32 ) {    //Saves frames, name = time
              picSaver(frame);
          }

          if( waitKey(1) == 27 ) 
              break;
    }


    return 0;
}

void picSaver(Mat pic) {
    std::time_t epoch =  std::time(nullptr);
    String time = to_string(epoch);
    time.append(".jpg");

    imwrite(time , pic);
}
