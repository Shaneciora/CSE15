//-----------------------------------------------------------------------------
// Simulation.c
//-----------------------------------------------------------------------------
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Job.h"
#include"IntegerQueue.h"

//-----------------------------------------------------------------------------
// The following function may be of use in assembling the initial backup array.
// You may use it as is, alter it as you see fit, or delete it altogether.
//-----------------------------------------------------------------------------

// getjob()
// Reads two numbers from file in, and returns a new Job with those numbers
// as arrival and duration.
Job getJob(FILE* in){
   int a, d;
   fscanf(in, "%d %d\n", &a, &d);
   return newJob(a, d);
}

//-----------------------------------------------------------------------------
// The following stub for function main() contains a possible algorithm for
// this project.  Follow it if you like.  Note that there are no instructions
// included below for writing to either of the output files.  You must
// intersperse those commands as necessary.
//-----------------------------------------------------------------------------

// main()
int main(int argc, char* argv[]){

   // check command line arguments
   //
   // open files for reading and writing
   //
   // read in m jobs from input file and place them in backup array
   //
   // declare and initialize an array of m-1 processor Queues along with
   // any necessary storage queues
   //
   // loop: run simulation with n processors for n=1 to n=m-1 {
   //
   //    place Job indices from backup array into storage queue
   //
   //    loop: process all Jobs in this simulation {
   //
   //       determine the time of the next arrival or finish event and update time
   //
   //       if any Jobs finish now, then complete them in the order they appear in
   //       the queue array, i.e. lowest index first.
   //
   //       if any Jobs arrive now, then assign them to a processor queue
   //       of minimum length and with lowest index in the queue array.
   //
   //    } end loop
   //
   //    compute the total wait, maximum wait, and average wait for
   //    all Jobs, then reset finish times for next simulation
   //
   // } end loop
   //
   // free all heap memory, close input and output files

   return EXIT_SUCCESS;
}
