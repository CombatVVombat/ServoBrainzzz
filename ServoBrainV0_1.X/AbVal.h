/* 
 * File:   AbVal.h
 * Author: JRK
 *
 * Created on April 26, 2013, 7:04 PM
 */

#ifndef ABVAL_H
#define	ABVAL_H

unsigned long abval(signed long val)
{
    return (val<0 ? (-val) : val);
}


#endif	/* ABVAL_H */

