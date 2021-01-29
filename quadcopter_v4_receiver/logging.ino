#include <Arduino.h>

#define NUM_SAMPLES 50

//unsigned long my_micros[NUM_SAMPLES];
//short my_data[NUM_SAMPLES];

class Logging
{  
  public:
    Logging(void);
    void log_start_task(short task_nr);
    void log_end_task(short task_nr);
    //void print_data(void);


    bool done_flag = false;
    short counter = 0;
    unsigned long time_stamp = 0;
  
};



Logging::Logging (void) {

    bool done_flag = false;
    short counter = 0;
    unsigned long time_stamp = 0;
}


void Logging::log_start_task(short task_nr)
{
    time_stamp = micros();
    Serial.print(0);
    Serial.print(" ");
    Serial.println(time_stamp - 1);
    Serial.print(task_nr);
    Serial.print(" ");
    Serial.println(time_stamp);
    
//    my_data[counter] = 0;
//    my_micros[counter++] = time_stamp - 1;
//    my_data[counter] = task_nr;
//    my_micros[counter++] = time_stamp; 
}

void Logging::log_end_task(short task_nr)
{
    time_stamp = micros();
    Serial.print(task_nr);
    Serial.print(" ");
    Serial.println(time_stamp - 1);
    Serial.print(0);
    Serial.print(" ");
    Serial.println(time_stamp);
//    my_data[counter] = task_nr;
//    my_micros[counter++] = time_stamp - 1;
//    my_data[counter] = 0;
//    my_micros[counter++] = time_stamp; 
}


//void Logging::print_data(void)
//{
//  if(counter >= NUM_SAMPLES && !done_flag)
//  {
//    for (int i = 0; i < NUM_SAMPLES; i++)
//    {
//      Serial.print(my_micros[i]);
//      Serial.print("    ");
//      Serial.println(my_data[i]);
//      done_flag = true;  
//    }
//  }
//}


