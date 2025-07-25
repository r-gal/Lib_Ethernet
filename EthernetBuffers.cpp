 #include <stdio.h>
 #include <stdio.h>
#include <stdlib.h>
#include <cstring>



#include "EthernetBuffers.hpp"

#define RX_BUFFER_SIZE 1540

#include "HeapManager.hpp"

#if MEM_USE_RAM2 == 1
extern HeapManager_c ramD2Manager;
#endif
extern HeapManager_c baseManager;

uint8_t* EthernetBuffers_c::NewBuffer(void)
{
#if MEM_USE_RAM2 == 1
  uint8_t* buffer = (uint8_t*)ramD2Manager.Malloc(RX_BUFFER_SIZE,1025);
  if(buffer == nullptr)
  {
     buffer = (uint8_t*)baseManager.Malloc(RX_BUFFER_SIZE,1025);
  }
#else

  uint8_t* buffer = (uint8_t*)baseManager.Malloc(RX_BUFFER_SIZE,1025);
#endif

  //uint8_t* buffer = new uint8_t[RX_BUFFER_SIZE] ;
  return buffer;
}


void EthernetBuffers_c::DeleteBuffer(uint8_t* buffer)
{



  delete buffer;

}
