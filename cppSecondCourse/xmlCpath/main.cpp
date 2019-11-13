#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Sequencer.h"
#include <libxml/parser.h>
#include <libxml/xpath.h>

std::string relativeMoveTemplate = "<sequencer_prog><slave>0</slave><definitions><vars>WB_RampRelPos;WB_RampRelVar</vars><expr1>WB_RampRelPos = DATA_PHY(14)</expr1><expr2>WB_RampRelVar = WB_RampRelPos - 40</expr2></definitions><update><expressions>expr1;expr2</expressions></update><synth_set><unit>ramp</unit><type>ramp</type><stream>phys14</stream><stream2>phys15</stream2><rate>5</rate><end_rate>0</end_rate><acc>0</acc><end_ampl>WB_RampRelVar</end_ampl><end_time>50</end_time></synth_set><clear><triggers>TRIG_SYNTH_R</triggers></clear><start></start><wait><triggers>TRIG_SYNTH_R</triggers></wait><synth_set><unit>ramp</unit><type>const</type></synth_set><synth_set><unit>wave1</unit><type>reset</type></synth_set><synth_set><unit>wave2</unit><type>reset</type></synth_set><synth_set><unit>stream</unit><type>reset</type></synth_set><synth_set><unit>curve</unit><type>reset</type></synth_set><start></start></sequencer_prog>";
std::string absoluteMoveTemplate="<sequencer_prog><slave>0</slave><definitions></definitions><synth_set><unit>ramp</unit><type>acc</type><stream>phys14</stream><stream2>phys15</stream2><rate>5</rate><end_rate>0</end_rate><acc>0</acc><end_ampl>10</end_ampl><end_time>50</end_time></synth_set><clear><triggers>TRIG_SYNTH_R</triggers></clear><start></start><wait><triggers>TRIG_SYNTH_R</triggers></wait><synth_set><unit>ramp</unit><type>const</type></synth_set><synth_set><unit>wave1</unit><type>reset</type></synth_set><synth_set><unit>wave2</unit><type>reset</type></synth_set><synth_set><unit>stream</unit><type>reset</type></synth_set><synth_set><unit>curve</unit><type>reset</type></synth_set><start></start></sequencer_prog>";

int main(int argc, char **argv) {
    Sequencer seq(absoluteMoveTemplate);
    printf("%s\n",absoluteMoveTemplate.c_str());
    printf("%s\n",seq.getXml().c_str());



	return (1);
}