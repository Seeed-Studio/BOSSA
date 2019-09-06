///////////////////////////////////////////////////////////////////////////////
// BOSSA
//
// Copyright (c) 2011-2018, ShumaTech
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the <organization> nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///////////////////////////////////////////////////////////////////////////////
#include "IMXRTFlash.h"

#include <assert.h>
#include <unistd.h>
#include <stdio.h>



#define ERASE_BLOCK_PAGES 32

IMXRTFlash::IMXRTFlash(Samba& samba,
                   const std::string& name,
                   uint32_t addr,
                   uint32_t pages,
                   uint32_t size,
                   uint32_t planes,
                   uint32_t lockRegions,
                   uint32_t user,
                   uint32_t stack,
                   bool canBootFlash)
    : Flash(samba, name, addr, pages, size, planes, lockRegions, user, stack),
      _canBootFlash(canBootFlash)
{

    eraseAuto(true);
  
}

IMXRTFlash::~IMXRTFlash()
{
}

void
IMXRTFlash::eraseAll(uint32_t offset)
{
   printf("Didn't support this function.");
   return;
}

void
IMXRTFlash::erase(uint32_t offset, uint32_t size)
{
   printf("Didn't support this function.");
   return;
}

void
IMXRTFlash::eraseAuto(bool enable)
{
    return ;
}

std::vector<bool>
IMXRTFlash::getLockRegions()
{
    std::vector<bool> regions(_lockRegions);
    uint32_t fsr0;
    uint32_t fsr1;


    return regions;
}

bool
IMXRTFlash::getSecurity()
{
   return false;
}

bool
IMXRTFlash::getBod()
{
   return false;
}

bool
IMXRTFlash::getBor()
{
    return false;
}

bool
IMXRTFlash::getBootFlash()
{
   return false;
}

void
IMXRTFlash::writeOptions()
{
  
}

void
IMXRTFlash::writePage(uint32_t page)
{
    usleep(10);
   _samba.program(page * _size, _onBufferA ? _pageBufferA : _pageBufferB);

}

void
IMXRTFlash::readPage(uint32_t page, uint8_t* data)
{
  
}

