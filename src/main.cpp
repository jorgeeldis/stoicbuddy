#include "unihiker_k10.h"
#include "asr.h"
#include "StoicResponses.h"

void commands();
void philosopher(String emotion);
void answer(String msg);
void showCommands();

UNIHIKER_K10 k10;
Music music;
ASR asr;
uint8_t screen_dir = 2;
int idle = 0;
bool musicStop = false;
bool sleepingstate = false;
String neutral = "S:/philosopher192x192.png";
String happy = "S:/philosopherhappy192x192.png";
String sad = "S:/philosophersad192x192.png";
String sleeping = "S:/philosophersleeping192x192.png";
String talking = "S:/philosophertalking192x192.png";
String think = "S:/philosopherthink192x192.png";

void setup()
{
  k10.begin();
  randomSeed(analogRead(A0));
  int randomgreeting = random(0, 3);
  asr.asrInit(ONCE, EN_MODE, 6000);
  delay(2000);
  commands();
  k10.initScreen(screen_dir);
  k10.creatCanvas();
  k10.initSDFile();
  k10.setScreenBackground(0xebddab);
  k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
  philosopher(neutral);
  k10.canvas->canvasRectangle(20, 230, 205, 80, 0x8A3F35, 0xebddab, false);
  answer(StoicResponses::greetings[randomgreeting]);
  k10.canvas->updateCanvas();
}
void loop()
{
  idle++;
  delay(1000);
  if ((k10.buttonA->isPressed()))
  {
    showCommands();
  }
  if ((k10.buttonB->isPressed()))
  {
    idle = 0;
    int randomgreeting = random(0, 3);
    k10.canvas->canvasClear();
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(neutral);
    k10.canvas->canvasRectangle(20, 230, 205, 80, 0x8A3F35, 0xebddab, false);
    answer(StoicResponses::greetings[randomgreeting]);
    k10.canvas->updateCanvas();
  }
  if (asr.isDetectCmdID(1))
  {
    k10.canvas->canvasClear();
    int randomhappy = random(0, 3);
    int randomhappyrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::happyness[randomhappy]);
    delay(1000);
    answer(StoicResponses::happynessrecom[randomhappyrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(happy);
    idle = 0;
  }

  if (asr.isDetectCmdID(2))
  {
    k10.canvas->canvasClear();
    int randomsadness = random(0, 3);
    int randomsadnessrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::sadness[randomsadness]);
    delay(1000);
    answer(StoicResponses::sadnessrecom[randomsadnessrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(sad);
    idle = 0;
  }

  if (asr.isDetectCmdID(3))
  {
    k10.canvas->canvasClear();
    int randomstress = random(0, 3);
    int randomstressrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::stress[randomstress]);
    delay(1000);
    answer(StoicResponses::stressrecom[randomstressrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(4))
  {
    k10.canvas->canvasClear();
    int randomafraid = random(0, 3);
    int randomafraidrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::afraid[randomafraid]);
    delay(1000);
    answer(StoicResponses::afraidrecom[randomafraidrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(5))
  {
    k10.canvas->canvasClear();
    int randomangry = random(0, 3);
    int randomangryrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::angry[randomangry]);
    delay(1000);
    answer(StoicResponses::angryrecom[randomangryrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(sad);
    idle = 0;
  }

  if (asr.isDetectCmdID(6))
  {
    k10.canvas->canvasClear();
    int randomoverwhelmed = random(0, 3);
    int randomoverwhelmedrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::overwhelmed[randomoverwhelmed]);
    delay(1000);
    answer(StoicResponses::overwhelmedrecom[randomoverwhelmedrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(7))
  {
    k10.canvas->canvasClear();
    int randommistake = random(0, 3);
    int randommistakerecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::mistake[randommistake]);
    delay(1000);
    answer(StoicResponses::mistakerecom[randommistakerecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(happy);
    idle = 0;
  }

  if (asr.isDetectCmdID(8))
  {
    k10.canvas->canvasClear();
    int randomnocontrol = random(0, 3);
    int randomnocontrolrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::nocontrol[randomnocontrol]);
    delay(1000);
    answer(StoicResponses::nocontrolrecom[randomnocontrolrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(9))
  {
    k10.canvas->canvasClear();
    int randomunmotivated = random(0, 3);
    int randomunmotivatedrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::unmotivated[randomunmotivated]);
    delay(1000);
    answer(StoicResponses::unmotivatedrecom[randomunmotivatedrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(10))
  {
    k10.canvas->canvasClear();
    int randomwisdom = random(0, 3);
    int randomwisdomrecom = random(0, 3);
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer(StoicResponses::wisdom[randomwisdom]);
    delay(1000);
    answer(StoicResponses::wisdomrecom[randomwisdomrecom]);
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(happy);
    idle = 0;
  }

  if (asr.isDetectCmdID(11))
  {
    k10.canvas->canvasClear();
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Here is some music for you to relax. It's one of my favorites, please enjoy. If you want to talk to me again, please restart the device.");
    delay(1000);
    philosopher(happy);
    music.playTFCardAudio("S:/furelise.wav");
    idle = 0;
  }

  if (idle == 30)
  {
    k10.canvas->canvasClear();
    k10.canvas->canvasText("Stoic Buddy", 50, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 12, true);
    sleepingstate = true;
    philosopher(sleeping);
    answer("Zzz...");
  }
}

void showCommands()
{
  idle = 0;
  k10.canvas->canvasClear();
  k10.canvas->canvasText("Commands", 10, 30, 0x8A3F35, k10.canvas->eCNAndENFont24, 9, false);
  k10.canvas->canvasText("- I am happy -", 10, 60, 0x2F3145, k10.canvas->eCNAndENFont16, 15, false);
  k10.canvas->canvasText("- I am sad -", 10, 80, 0x2F3145, k10.canvas->eCNAndENFont16, 13, false);
  k10.canvas->canvasText("- I am stressed -", 10, 100, 0x2F3145, k10.canvas->eCNAndENFont16, 18, false);
  k10.canvas->canvasText("- I am afraid -", 10, 120, 0x2F3145, k10.canvas->eCNAndENFont16, 16, false);
  k10.canvas->canvasText("- I am angry -", 10, 140, 0x2F3145, k10.canvas->eCNAndENFont16, 15, false);
  k10.canvas->canvasText("- I am overwhelmed -", 10, 160, 0x2F3145, k10.canvas->eCNAndENFont16, 21, false);
  k10.canvas->canvasText("- I made a mistake -", 10, 180, 0x2F3145, k10.canvas->eCNAndENFont16, 21, false);
  k10.canvas->canvasText("- I cannot control -", 10, 200, 0x2F3145, k10.canvas->eCNAndENFont16, 21, false);
  k10.canvas->canvasText("- I feel unmotivated -", 10, 220, 0x2F3145, k10.canvas->eCNAndENFont16, 23, false);
  k10.canvas->canvasText("- Give me wisdom -", 10, 240, 0x2F3145, k10.canvas->eCNAndENFont16, 19, false);
  k10.canvas->canvasText("- Play music -", 10, 260, 0x2F3145, k10.canvas->eCNAndENFont16, 15, false);
  k10.canvas->updateCanvas();
}

void commands()
{
  asr.addASRCommand(1, "I am happy");
  asr.addASRCommand(2, "I am sad");
  asr.addASRCommand(3, "I am stressed");
  asr.addASRCommand(4, "I am afraid");
  asr.addASRCommand(5, "I am angry");
  asr.addASRCommand(6, "I am overwhelmed");
  asr.addASRCommand(7, "I made a mistake");
  asr.addASRCommand(8, "I cannot control");
  asr.addASRCommand(9, "I feel unmotivated");
  asr.addASRCommand(10, "Give me wisdom");
  asr.addASRCommand(11, "Play music");
}

void philosopher(String emotion)
{
  k10.canvas->canvasRectangle(50, 58, 150, 150, 0xebddab, 0xebddab, true);
  k10.canvas->canvasDrawImage(20, 50, emotion);
  k10.canvas->updateCanvas();
}

void answer(String msg)
{
  String firstline = "";
  String secondline = "";
  String thirdline = "";
  String fourthline = "";
  String fifthline = "";
  k10.canvas->canvasRectangle(10, 230, 220, 80, 0x8A3F35, 0xebddab, true);
  for (int i = 0; i < msg.length(); i++)
  {
    if (i < 32)
    {
      firstline += msg[i];
      k10.canvas->canvasText(firstline, 20, 235, 0x2F3145, Canvas::eCNAndENFont16, 34, false);
      k10.canvas->updateCanvas();
    }
    else if (i >= 32 && i < 64)
    {
      secondline += msg[i];
      k10.canvas->canvasText(secondline, 20, 248, 0x2F3145, Canvas::eCNAndENFont16, 34, false);
      k10.canvas->updateCanvas();
    }
    else if (i >= 64 && i < 96)
    {
      thirdline += msg[i];
      k10.canvas->canvasText(thirdline, 20, 261, 0x2F3145, Canvas::eCNAndENFont16, 34, false);
      k10.canvas->updateCanvas();
    }
    else if (i >= 96 && i < 128)
    {
      fourthline += msg[i];
      k10.canvas->canvasText(fourthline, 20, 274, 0x2F3145, Canvas::eCNAndENFont16, 34, false);
      k10.canvas->updateCanvas();
    }
    else if (i >= 128 && i < 160)
    {
      fifthline += msg[i];
      k10.canvas->canvasText(fifthline, 20, 287, 0x2F3145, Canvas::eCNAndENFont16, 34, false);
      k10.canvas->updateCanvas();
    }
  }
}
