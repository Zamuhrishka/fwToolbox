/**
* @file    		crc.h
* @author  		Kovalchuk Alexander
* @email  		roux@yandex.ru
* @brief   		This file contains files for calculate crc8/16/32.
**/

#pragma once

/* C++ detection */
#ifdef __cplusplus
	extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________
/**
 * @brief		This function calculate checksum crc8.
 * 				Used polynomial: x^8 + x^5 + x^4 + 1 (0x31).
 * 				Init  : 0xFF
 * 				Revert: false
 * 				XorOut: 0x00
 * 				Check : 0xF7 ("123456789")
 *
 * @param[in] 	pcBlock: pointer to the data buffer.
 * @param[in] 	len: size of data buffer.
 *
 * @return 		calculated crc8 value.
**/
uint8_t crc8(const uint8_t *pcBlock, size_t len);

/**
 * @brief		This function calculate by table method checksum crc8.
 * 				Used polynomial: x^8 + x^5 + x^4 + 1 (0x31).
 * 				Init  : 0xFF
 * 				Revert: false
 * 				XorOut: 0x00
 * 				Check : 0xF7 ("123456789")
 *
 * @param[in] 	pcBlock: pointer to the data buffer.
 * @param[in] 	len: size of data buffer.
 *
 * @return 		calculated crc8 value.
**/
uint8_t crc8_table(const uint8_t *pcBlock, size_t len);

/**
 * @brief		This function calculate checksum crc16.
 * 				Used polynomial: x^16 + x^12 + x^5 + 1 (0x1021).
 * 				Init  : 0xFFFF
 * 				Revert: false
 * 				XorOut: 0x0000
 * 				Check : 0x29B1 ("123456789")
 *
 * @param[in] 	pcBlock: pointer to the data buffer.
 * @param[in] 	len: size of data buffer.
 *
 * @return 		calculated crc16 value.
**/
uint16_t crc16(const uint8_t *pcBlock, size_t len);

/**
 * @brief		This function calculate by table method checksum crc16.
 * 				Used polynomial: x^16 + x^12 + x^5 + 1 (0x1021).
 * 				Init  : 0xFFFF
 * 				Revert: false
 * 				XorOut: 0x0000
 * 				Check : 0x29B1 ("123456789")
 *
 * @param[in] 	pcBlock: pointer to the data buffer.
 * @param[in] 	len: size of data buffer.
 *
 * @return 		calculated crc16 value.
**/
uint16_t crc16_table(const uint8_t *pcBlock, size_t len);

/**
 * @brief		This function calculate checksum crc32.
 * 				Used polynomial: x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11
                       + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1 (0x04C11DB7)
 * 				Init  : 0xFFFFFFFF
 * 				Revert: false
 * 				XorOut: 0xFFFFFFFF
 * 				Check : 0xCBF43926 ("123456789")
 *
 * @param[in] 	pcBlock: pointer to the data buffer.
 * @param[in] 	len: size of data buffer.
 *
 * @return 		calculated crc32 value.
**/
uint_least32_t crc32(const uint8_t * buf, size_t len);

/**
 * @brief		This function calculate by table method checksum crc32.
 * 				Used polynomial: x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11
 *                      + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1 (0x04C11DB7)
 * 				Init  : 0xFFFFFFFF
 * 				Revert: false
 * 				XorOut: 0xFFFFFFFF
 * 				Check : 0xCBF43926 ("123456789")
 *
 * @param[in] 	pcBlock: pointer to the data buffer.
 * @param[in] 	len: size of data buffer.
 *
 * @return 		calculated crc32 value.
**/
uint_least32_t crc32_table(const uint8_t *buf, size_t len);

/* C++ detection */
#ifdef __cplusplus
}
#endif
