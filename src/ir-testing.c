#pragma config(Sensor, S2,     HTIRS2,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-irseeker-v2.h"

void displayText(int nLineNumber, string cChar, int nValueDC, int nValueAC);

task main()
{
	string sDisplay;

	int _dirDC = 0;
	int _dirAC = 0;

	int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;
	int acS1, acS2, acS3, acS4, acS5 = 0;

	tHTIRS2DSPMode _mode = DSP_1200;

	if (HTIRS2setDSPMode(HTIRS2, _mode) == 0)
	{
		eraseDisplay();

		nxtDisplayCenteredTextLine(0, "ERROR!");

		PlaySound(soundBeepBeep);

		sleep(300);

		return;
	}

	eraseDisplay();

	while (true)
	{
		_dirDC = HTIRS2readDCDir(HTIRS2);
		if (_dirDC < 0)
			break;

		_dirAC = HTIRS2readACDir(HTIRS2);
		if (_dirAC < 0)
			break;

		if (!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5))
			break;

		if (!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5))
			break;
		/*
		displayText(2, "D", _dirDC, _dirAC);
		displayText(3, "0", dcS1, acS1);
		displayText(4, "1", dcS2, acS2);
		displayText(5, "2", dcS3, acS3);
		displayText(6, "3", dcS4, acS4);
		displayText(7, "4", dcS5, acS5);
		*/


		StringFormat(sDisplay, "D:   DC   AC %4d", _dirAC);
		nxtDisplayTextLine(1, sDisplay);

		StringFormat(sDisplay, "1:   %4d   %4d", dcS1, acS1);
		nxtDisplayTextLine(2, sDisplay);

		StringFormat(sDisplay, "2:   %4d   %4d", dcS2, acS2);
		nxtDisplayTextLine(3, sDisplay);

		StringFormat(sDisplay, "3:   %4d   %4d", dcS3, acS3);
		nxtDisplayTextLine(4, sDisplay);

		StringFormat(sDisplay, "4:   %4d   %4d", dcS4, acS4);
		nxtDisplayTextLine(5, sDisplay);

		StringFormat(sDisplay, "5:   %4d   %4d", dcS5, acS5);
		nxtDisplayTextLine(6, sDisplay);

		sleep(10);
	}
}