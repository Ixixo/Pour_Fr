/***************************************************************************//**
 * @file    ads7885Pic32.h
 * @author  Ixchel Intelligent Systems
 * @version 1.0
 * @date    24/10/13
 *
 * Header de la bibliothèque ads7885Pic32
 ******************************************************************************/

#ifndef ADS7885PIC32_H
#define	ADS7885PIC32_H

/*** INCLUDES *****************************************************************/

    #include <plib.h>


/*** MACROS *******************************************************************/

//  #define slaveSelectActive()     LATGbits.LATG6 = 0
//  #define slaveSelectDesactive()  LATGbits.LATG6 = 1    //!
    #define IL_slave_select_active()       LATDbits.LATD9 = 0
    #define IL_slave_select_desactive()    LATDbits.LATD9 = 1

    #define VO_slave_select_active()       LATAbits.LATA14 = 0
    #define VO_slave_select_desactive()    LATAbits.LATA14 = 1

    #define VI_slave_select_active()       LATAbits.LATA15 = 0
    #define VI_slave_select_desactive()    LATAbits.LATA15 = 1

    #define cnvstActive()           LATEbits.LATE8 = 0
    #define cnvstDesactive()        LATEbits.LATE8 = 1
    #define busy()                  LATAbits.LATA6
    #define sendCode                (unsigned int) 0xF0F0F0F0


/*** PROTOTYPES ***************************************************************/

/***************************************************************************//**
 * Configuration ad7634 via liaison SPI
 *
 * Fmax=2Mbits/s soit 0.4ms pour 32bits avec la fréquence du bus des périph non
 * divisée est donc 2MHz
 *
 * @param chn       Canal à ouvrir
 * @param srcClkDiv Diviseur de fréquence d'horloge
 *
 * @return  chn si la configuration est réussi, -1 sinon
 ******************************************************************************/
SpiChannel ad7634Pic32Open(SpiChannel chn, unsigned int srcClkDiv);

/***************************************************************************//**
* Lit les donnée envoyées par l'ADC
 *
 * @param chn   Canal à lire
 * @param data  Pointeur vers l'emplacement de stockage de la donnée
 ******************************************************************************/
 void ad7634Pic32Read(SpiChannel chn, int* data);

/***************************************************************************//**
 * Ferme le canal
 *
 * @param chn   Canal à fermer
 ******************************************************************************/
 void ad7634Pic32Close(SpiChannel chn);

#endif	/* ADS7885PIC32_H */