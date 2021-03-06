/*
 * File:   app_rtc_action.c
 * Author: jerome
 *
 * Created on 17 novembre 2018, 07:16
 */


#include "app.h"

void manageRtcAction(  )
{
    bool flag;
    int i;
    
    if ( OPENFEEDER_IS_AWAKEN == appData.openfeeder_state && RTCC_ALARM_SLEEP_OPENFEEDER == appData.rtcc_alarm_action )
    {
        appData.state = APP_STATE_SLEEP;
        return;
    }

    if ( OPENFEEDER_IS_SLEEPING == appData.openfeeder_state && RTCC_ALARM_WAKEUP_OPENFEEDER == appData.rtcc_alarm_action )
    {
        appData.state = APP_STATE_WAKE_UP;
        return;
    }

    if ( RTCC_RTC_CALIBRATION == appData.rtcc_alarm_action )
    {
        calibrateDateTime( );
    }

    if ( RTCC_DS3231_TEMPERATURE == appData.rtcc_alarm_action )
    {
        if (0 < APP_I2CMasterSeeksSlaveDevice(DS3231_I2C_ADDR, DS3231_I2C_ADDR))
        {
            /* Log event if required */
            if ( true == appDataLog.log_events )
            {
               store_event(OF_DS3231_GET_TEMPERATURE); 
            }

            getDateTime( );
            getDS3231Temperature( );
            appDataLog.ds3231_temp[appDataLog.num_ds3231_temp_stored][0] = (float)appData.current_time.tm_hour;
            appDataLog.ds3231_temp[appDataLog.num_ds3231_temp_stored][1] = (float)appData.current_time.tm_min;
            appDataLog.ds3231_temp[appDataLog.num_ds3231_temp_stored][2] = appData.ext_temperature;
            ++appDataLog.num_ds3231_temp_stored;
        }
    }

    if ( RTCC_ALARM_SET_ATTRACTIVE_LEDS_OFF == appData.rtcc_alarm_action )
    {
        if ( ATTRACTIVE_LEDS_ON == appDataAttractiveLeds.status )
        {
            setAttractiveLedsOff( );
        }
    }

    if ( RTCC_ALARM_SET_ATTRACTIVE_LEDS_ON == appData.rtcc_alarm_action )
    {
        if ( ATTRACTIVE_LEDS_OFF == appDataAttractiveLeds.status )
        {
            setAttractiveLedsOn( );
        }
    }

    if ( RTCC_ALARM_ALT_ATTRACTIVE_LEDS == appData.rtcc_alarm_action && false == appData.punishment_state )
    {
        if ( rand( ) > (RAND_MAX/2) ) // t / RAND_MAX ) > 0.5
        {
            appDataAttractiveLeds.current_color_index = !appDataAttractiveLeds.current_color_index;
            setAttractiveLedsColor( );

            /* Log event if required */
            if ( true == appDataLog.log_events )
            {
                if ( 0 == appDataAttractiveLeds.current_color_index )
                {
                    store_event(OF_CAL_A);
                }
                else
                {
                    store_event(OF_CAL_B);
                }
            }  
        }                                
    }
    
    if ( RTCC_ALARM_ALT_ATTRACTIVE_LEDS_PATTERN == appData.rtcc_alarm_action && false == appData.punishment_state )
    {
        int randomInteger = rand( );

        if (ONE_LED == appDataAttractiveLeds.pattern_number)
        {
            for (i=0;i<4;i++)
            {
               appDataAttractiveLeds.pattern[i] = 1; 
            }

            if ( randomInteger > (RAND_MAX/4*3) )
            {
                appDataAttractiveLeds.pattern_one_led_current = 0;

                /* Log event if required */
                if ( true == appDataLog.log_events )
                {
                    store_event( OF_GO_NO_GO_ONE_1 );
                }
            }                            
            else if ( randomInteger > (RAND_MAX/2) )
            {
                appDataAttractiveLeds.pattern_one_led_current = 1;

                /* Log event if required */
                if ( true == appDataLog.log_events )
                {
                    store_event( OF_GO_NO_GO_ONE_2 );
                }
            }
            else if ( randomInteger > (RAND_MAX/4) )
            {
                appDataAttractiveLeds.pattern_one_led_current = 2; 

                /* Log event if required */
                if ( true == appDataLog.log_events )
                {
                    store_event( OF_GO_NO_GO_ONE_3 );
                }
            }
            else
            {
                appDataAttractiveLeds.pattern_one_led_current = 3;

                /* Log event if required */
                if ( true == appDataLog.log_events )
                {
                    store_event( OF_GO_NO_GO_ONE_4 );
                }
            }

            appDataAttractiveLeds.pattern[appDataAttractiveLeds.pattern_one_led_current] = 0;      

           setAttractiveLedsPattern( );
        }
        else if (ALL_LEDS == appDataAttractiveLeds.pattern_number)
        {
            if ( randomInteger > (RAND_MAX/100*appDataAttractiveLeds.pattern_percent) )
            {
                for (i=0;i<4;i++)
                {
                   appDataAttractiveLeds.pattern[i] = !appDataAttractiveLeds.pattern[i]; 
                }
                appDataAttractiveLeds.pattern_idx = !appDataAttractiveLeds.pattern_idx;
                setAttractiveLedsPattern( );

                appDataAttractiveLeds.pattern_percent = 100-appDataAttractiveLeds.pattern_percent;

                /* Log event if required */
                if ( true == appDataLog.log_events )
                {
                    if ( 0 == appDataAttractiveLeds.pattern_idx )
                    {
                        store_event( OF_GO_NO_GO_ALL_ON );
                    }
                    else
                    {
                        store_event( OF_GO_NO_GO_ALL_OFF );
                    }
                }                                
            }
        }
        else
        {
            if ( randomInteger > (RAND_MAX/2) )
            {
                for (i=0;i<4;i++)
                {
                   appDataAttractiveLeds.pattern[i] = !appDataAttractiveLeds.pattern[i]; 
                }
                appDataAttractiveLeds.pattern_idx = !appDataAttractiveLeds.pattern_idx;
                setAttractiveLedsPattern( );   

                /* Log event if required */
                if ( true == appDataLog.log_events )
                {
                    if ( 0 == appDataAttractiveLeds.pattern_idx )
                    {
                        if ( LEFT_RIGHT_LEDS == appDataAttractiveLeds.pattern_number )
                        {
                            store_event( OF_GO_NO_GO_LR_L );
                        }
                        else
                        {
                            store_event( OF_GO_NO_GO_TB_T );
                        }
                    }
                    else
                    {
                        if ( LEFT_RIGHT_LEDS == appDataAttractiveLeds.pattern_number )
                        {
                            store_event( OF_GO_NO_GO_LR_R );
                        }
                        else
                        {
                            store_event( OF_GO_NO_GO_TB_B );
                        }
                    }
                }  
            }
        }

    }
    
    if ( DOOR_OPENED != appDataDoor.reward_door_status && RTCC_ALARM_OPEN_DOOR == appData.rtcc_alarm_action )
    {
        /* Open reward door */
        servomotorPowerEnable( );

        appDataServo.ton_cmd = servomotorGetDoorPosition( );
        appDataServo.ton_goal = appDataServo.ton_max;

        if ( appDataServo.ton_cmd != appDataServo.ton_goal )
        {
            appDataDoor.reward_door_status = DOOR_MOVING;
            while ( DOOR_MOVED != appDataDoor.reward_door_status );
        }
        appDataDoor.reward_door_status = DOOR_OPENED;
#if defined (USE_UART1_SERIAL_INTERFACE) && defined (DISPLAY_SERVO_POSITION)
        servomotorGetDoorPosition( );
#endif  
        servomotorPowerDisable( );
    }

    if ( DOOR_CLOSED != appDataDoor.reward_door_status && RTCC_ALARM_CLOSE_DOOR == appData.rtcc_alarm_action )
    {
        /* Close reward door */
        servomotorPowerEnable( );

        appDataServo.ton_cmd = servomotorGetDoorPosition( );
        appDataServo.ton_goal = appDataServo.ton_min;

        if ( appDataServo.ton_cmd != appDataServo.ton_goal )
        {
            appDataDoor.reward_door_status = DOOR_MOVING;
            while ( DOOR_MOVED != appDataDoor.reward_door_status );
        }
        appDataDoor.reward_door_status = DOOR_CLOSED;
#if defined (USE_UART1_SERIAL_INTERFACE) && defined (DISPLAY_SERVO_POSITION)
        servomotorGetDoorPosition( );
#endif  
        servomotorPowerDisable( );
    }

    if ( RTCC_BATTERY_LEVEL_CHECK == appData.rtcc_alarm_action )
    {
        flag = isPowerBatteryGood( );
        appDataLog.battery_level[appDataLog.num_battery_level_stored][0] = appData.current_time.tm_hour;
        appDataLog.battery_level[appDataLog.num_battery_level_stored][1] = appData.battery_level;
        ++appDataLog.num_battery_level_stored;

        if ( false == flag )
        {
            appData.state = APP_STATE_FLUSH_DATA_BEFORE_ERROR;
            return;
        }
    }
    
    if ( RTCC_FOOD_LEVEL_CHECK == appData.rtcc_alarm_action && true == appData.chk_food_level )
    {
        flag = isEnoughFood( );
        if ( false == flag )
        {
            appData.state = APP_STATE_FLUSH_DATA_BEFORE_ERROR;
            return;
        }
    }
    
    if ( RTCC_RFID_FREQ_CHECK == appData.rtcc_alarm_action )
    {
        flag = isRfidFreqGood( );
        appDataLog.rfid_freq[appDataLog.num_rfid_freq_stored][0] = appData.current_time.tm_hour;
        appDataLog.rfid_freq[appDataLog.num_rfid_freq_stored][1] = appData.current_time.tm_min;
        appDataLog.rfid_freq[appDataLog.num_rfid_freq_stored][2] = appData.rfid_rdyclk;
        ++appDataLog.num_rfid_freq_stored;

        if ( false == flag )
        {
            appData.state = APP_STATE_FLUSH_DATA_BEFORE_ERROR;
            return;
        }
    }

    appData.rtcc_alarm_action = RTCC_ALARM_IDLE;
}


