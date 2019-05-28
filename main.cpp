#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <chrono>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
  VideoCapture vid(1);
  if(!vid.isOpened()){
    cout << "Error opening webcam stream" << endl;
    return -1;
  }
  
  auto start = chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);
  ostringstream filename;
  filename << "VideoCapture " << std::ctime(&start_time) << ".avi";
  string sFilename = filename.str();
  
  double frame_width = vid.get(CAP_PROP_FRAME_WIDTH);
  double frame_height = vid.get(CAP_PROP_FRAME_HEIGHT);

  VideoWriter video(filename.str(),VideoWriter::fourcc('M','J','P','G'), 30, Size(frame_width,frame_height),true);
  
  while(true) {
    Mat frame;
    vid >> frame;
    video.write(frame);
  }
}