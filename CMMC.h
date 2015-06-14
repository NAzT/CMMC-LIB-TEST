/* 
  CMMC.h - esp8266 library that calls functions periodically

  Copyright (c) 2014 Ivan Grokhotkov. All rights reserved.
  This file is part of the esp8266 core for Arduino environment.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef CMMC_H
#define CMMC_H

#include <stdint.h>
#include <stddef.h>

extern "C" {
	typedef struct _ETSTIMER_ ETSTimer;
}

class CMMC
{
public:
	CMMC();
	~CMMC();
	typedef void (*callback_t)(void);
	typedef void (*callback_with_arg_t)(void*);

	void detach();


protected:
	ETSTimer* _timer;
};


#endif//CMMC_H
