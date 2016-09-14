#include "SS_Setting.h"
#include "init.h"

#if defined (MKP4) || defined (MKP4_1) || defined (MKP4_2) || defined (MKP4_3) || defined (MKP4_4) || defined (MKP4_5)
    #include "stm32f37x.h"
#endif
#if defined (MKP2) || defined (MKP3) || defined (MKP3_1) || defined (MKP3_2) || defined (MKP3_3) || defined (MKP3_4) || defined (MKP3_5)
	#include    "stm32F10x.h"
#endif

//#include "SS.h"

//SettingsTypDef Settings;
//signed short *pAReg;

signed short SS_Setting_Get_TIMER_CCR_MIN()                                    // TIMER_CCR_MIN
{
    return Settings.StartAngMin;
}

signed short SS_Setting_Get_TIMER_CCR_MAX()                                    // TIMER_CCR_MAX
{
    return Settings.StartAngMax;
}

signed short SS_Setting_Get_TIME_PULSE()                                       // TIME_PULSE
{
    return Settings.StartPulse;
}

signed short SS_Setting_Get_TIME_SOFT()                                        // TIME_SOFT
{
    return Settings.StartTime;
}

signed short SS_Setting_Get_TIMER_CCR_BREAK()                                  // TIMER_CCR_BREAK
{
    return Settings.BreakAngle;
}

signed short SS_Setting_Get_TIME_PULSE_BREAK()                                 // TIME_PULSE_BREAK
{
    return Settings.BreakPulse;
}

signed short SS_Setting_Get_TIME_PRE_BREAK()                                   // TIME_PRE_BREAK
{
    return Settings.BreakOverrun;
}

signed short SS_Setting_Get_TIME_BREAK()                                       // TIME_BREAK
{
    return Settings.BreakTime;
}

void SS_Setting_init (signed short *pAReg)
{
    
  if ((EEPROM_read_16(21) < 0) || (EEPROM_read_16(21) > 100))                                           //если EEPROM пустая
      EEPROM_write_16 (21, TIMER_CCR_MIN);
  
  if ((EEPROM_read_16(23) < 500) || (EEPROM_read_16(23) > 600))                                           
      EEPROM_write_16 (23, TIMER_CCR_MAX);
  
  if ((EEPROM_read_16(25) < 350) || (EEPROM_read_16(25) > 400))
      EEPROM_write_16(25, TIME_PULSE);
        
  if  ((EEPROM_read_16(27) < 0) || (EEPROM_read_16(27) > 3000))
      EEPROM_write_16(27, TIME_SOFT);
  
  if  ((EEPROM_read_16(29) < 400) || (EEPROM_read_16(29) > 600))
      EEPROM_write_16(29, TIMER_CCR_BREAK);
  
  if  ((EEPROM_read_16(31) < 25) || (EEPROM_read_16(31) > 100))
      EEPROM_write_16(31, TIME_PULSE_BREAK);
      
  if  ((EEPROM_read_16(33) < 0) || (EEPROM_read_16(33) > 500))
      EEPROM_write_16(33, TIME_PRE_BREAK);
      
  if  ((EEPROM_read_16(35) < 0) || (EEPROM_read_16(35) > 1000))
      EEPROM_write_16(35, TIME_BREAK);
             
  
    Settings.StartAngMin  = EEPROM_read_16(21);
    Settings.StartAngMax  = EEPROM_read_16(23);
    Settings.StartPulse   = EEPROM_read_16(25);
    Settings.StartTime    = EEPROM_read_16(27);
    Settings.BreakAngle   = EEPROM_read_16(29);
    Settings.BreakPulse   = EEPROM_read_16(31);
    Settings.BreakOverrun = EEPROM_read_16(33);
    Settings.BreakTime    = EEPROM_read_16(35);
	
    pAReg [1] = Settings.StartAngMin;                                           //необходимо заполнить Аreg значениями (тут мы это делаем через указатель)
    pAReg [2] = Settings.StartAngMax;
    pAReg [3] = Settings.StartPulse;
    pAReg [4] = Settings.StartTime;
    pAReg [5] = Settings.BreakAngle;
    pAReg [6] = Settings.BreakPulse;
    pAReg [7] = Settings.BreakOverrun;
    pAReg [8] = Settings.BreakTime;  
	
}

void SS_Setting_write(signed short *pAReg)
{
    pAReg[14] = SS_GetSyncIn();
    
    //float convertion Ph_A
    unsigned short array_float_conv[2] = {0, 0};
    float temp_convert_float = 0;
    temp_convert_float = SS_Ia_RMS();
    array_float_conv [0] = *(((unsigned short*) (&temp_convert_float))+0);
    array_float_conv [1] = *(((unsigned short*) (&temp_convert_float))+1);
    // transmit float Ph_A
    pAReg[16] = array_float_conv [1];
    pAReg[17] = array_float_conv [0];
    
    
    //float convertion Ph_B
    array_float_conv[0] = 0;
    array_float_conv[0] = 0;
    temp_convert_float  = 0;
    
    temp_convert_float  = SS_Ib_RMS();
    array_float_conv [0] = *(((unsigned short*) (&temp_convert_float))+0);
    array_float_conv [1] = *(((unsigned short*) (&temp_convert_float))+1);
    // transmit float Ph_B
    pAReg[18] = array_float_conv [1];
    pAReg[19] = array_float_conv [0];

    //float convertion Ph_C
    array_float_conv[0] = 0;
    array_float_conv[0] = 0;
    temp_convert_float  = 0;
    
    temp_convert_float  = SS_Ic_RMS();
    array_float_conv [0] = *(((unsigned short*) (&temp_convert_float))+0);
    array_float_conv [1] = *(((unsigned short*) (&temp_convert_float))+1);
    // transmit float Ph_C
    pAReg[20] = array_float_conv [1];
    pAReg[21] = array_float_conv [0];
    
    ///////////////////////////////////
    pAReg[13] = SS_Get_Status();
    pAReg[15] = SS_Get_Alarm();
    
    
    if(SS_GetMode() == STOP)                                                    // допускается настройка блока, только в режиме полной остановки
        {
            pAReg[1] = (pAReg[1] >=   0 && pAReg[1] <=   100) ? pAReg[1] : Settings.StartAngMin; // TIMER_CCR_MIN 
            pAReg[2] = (pAReg[2] >= 500 && pAReg[2] <=   600) ? pAReg[2] : Settings.StartAngMax; // TIMER_CCR_MAX 
            pAReg[3] = (pAReg[3] >= 350 && pAReg[3] <=   400) ? pAReg[3] : Settings.StartPulse;  // TIME_PULSE
            pAReg[4] = (pAReg[4] >=   0 && pAReg[4] <=  3000) ? pAReg[4] : Settings.StartTime;   // TIME_SOFT     !
            pAReg[5] = (pAReg[5] >= 400 && pAReg[5] <=   600) ? pAReg[5] : Settings.BreakAngle;  // TIMER_CCR_BREAK
            pAReg[6] = (pAReg[6] >=  25 && pAReg[6] <=   100) ? pAReg[6] : Settings.BreakPulse;  // TIME_PULSE_BREAK
            pAReg[7] = (pAReg[7] >=   0 && pAReg[7] <=   500) ? pAReg[7] : Settings.BreakOverrun;// TIME_PRE_BREAK
            pAReg[8] = (pAReg[8] >=   0 && pAReg[8] <=  1000) ? pAReg[8] : Settings.BreakTime;   // TIME_BREAK
            
            
            if (Settings.StartAngMin   != pAReg[1])                               // если изменилось значение
            {
                Settings.StartAngMin    = pAReg[1];                               // обновляем структуру Setting
                EEPROM_write_16 (21, Settings.StartAngMin);                     // значение записали в Eeprom
                SS_Init_Update_Km();
                WWATCHDOG_RESET;
            }
            
            if (Settings.StartAngMax   != pAReg[2])
            {
                Settings.StartAngMax    = pAReg[2];
                EEPROM_write_16 (23, Settings.StartAngMax);
                SS_Init_Update_Km();
                WWATCHDOG_RESET;
            }
            
            if (Settings.StartPulse    != pAReg[3])
            {
                Settings.StartPulse     = pAReg[3];
                EEPROM_write_16 (25, Settings.StartPulse);
                WWATCHDOG_RESET;
            }
            
            if (Settings.StartTime     != pAReg[4])
            {
                Settings.StartTime      = pAReg[4];
                EEPROM_write_16 (27, Settings.StartTime);
                SS_Init_Update_Km();
                WWATCHDOG_RESET;
            }
            
            if (Settings.BreakAngle    != pAReg[5])
            {
                Settings.BreakAngle     = pAReg[5];
                EEPROM_write_16 (29, Settings.BreakAngle);
                WWATCHDOG_RESET;
            }
            
            if (Settings.BreakPulse    != pAReg[6])
            {
                Settings.BreakPulse     = pAReg[6];
                EEPROM_write_16 (31, Settings.BreakPulse);
                WWATCHDOG_RESET;
            }
            
            if (Settings.BreakOverrun  != pAReg[7])
            {
                Settings.BreakOverrun   = pAReg[7];
                EEPROM_write_16 (33, Settings.BreakOverrun);
                WWATCHDOG_RESET;
            }
            
            if (Settings.BreakTime     != pAReg[8])
            {
                Settings.BreakTime      = pAReg[8];
                EEPROM_write_16 (35, Settings.BreakTime);
                WWATCHDOG_RESET;
            }
            
            
            Settings.StartAngMax  = pAReg[2];
            Settings.StartPulse   = pAReg[3];
            Settings.StartTime    = pAReg[4];
            Settings.BreakAngle   = pAReg[5];
            Settings.BreakPulse   = pAReg[6];
            Settings.BreakOverrun = pAReg[7];
            Settings.BreakTime    = pAReg[8];
            
        }
    else 
    {
      pAReg [1] = Settings.StartAngMin;                                           //необходимо заполнить Аreg значениями (тут мы это делаем через указатель)
      pAReg [2] = Settings.StartAngMax;
      pAReg [3] = Settings.StartPulse;
      pAReg [4] = Settings.StartTime;
      pAReg [5] = Settings.BreakAngle;
      pAReg [6] = Settings.BreakPulse;
      pAReg [7] = Settings.BreakOverrun;
      pAReg [8] = Settings.BreakTime;  
    }
}
