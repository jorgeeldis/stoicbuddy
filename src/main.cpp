#include "unihiker_k10.h"
#include "asr.h"
#include "StoicResponses.h"

void commands();
void philosopher(String emotion);
void answer(String msg);

UNIHIKER_K10 k10;
Music music;
uint8_t screen_dir = 2;
int idle = 0;
ASR asr;
String neutral = "S:/philosopher192x192.png";
String happy = "S:/philosopherhappy192x192.png";
String sad = "S:/philosophersad192x192.png";
String sleeping = "S:/philosophersleeping192x192.png";
String talking = "S:/philosophertalking192x192.png";
String think = "S:/philosopherthink192x192.png";
bool musicStop = false;
bool sleepingstate = false;

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
  if (asr.isDetectCmdID(1))
  {
    int randomhappy = random(0, 3);
    int randomhappyrecom = random(0, 3);
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
    int randomsadness = random(0, 3);
    int randomsadnessrecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("I understand that sadness can visit us sometimes.");
    delay(1000);
    answer("Remember that emotions change with time, like clouds passing in the sky.");
    delay(1000);
    answer("Try to focus on one small thing you can do today that is within your control.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(sad);
    idle = 0;
  }

  if (asr.isDetectCmdID(3))
  {
    int randomstress = random(0, 3);
    int randomstressrecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Stress often appears when our mind tries to solve everything at once.");
    delay(1000);
    answer("Take a slow breath and focus only on the next step you can take.");
    delay(1000);
    answer("Small actions, done calmly, can solve many problems.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(4))
  {
    int randomafraid = random(0, 3);
    int randomafraidrecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Fear often comes from imagining the future.");
    delay(1000);
    answer("Bring your attention back to the present moment.");
    delay(1000);
    answer("Ask yourself what part of this situation you can influence.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(5))
  {
    int randomangry = random(0, 3);
    int randomangryrecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Anger is powerful, but it does not need to guide your actions.");
    delay(1000);
    answer("Take a moment to pause before responding.");
    delay(1000);
    answer("A calm mind allows you to choose the wiser path.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(sad);
    idle = 0;
  }

  if (asr.isDetectCmdID(6))
  {
    int randomoverwhelmed = random(0, 3);
    int randomoverwhelmedrecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("When everything feels overwhelming, it helps to slow down.");
    delay(1000);
    answer("Focus on one task, one breath, one moment at a time.");
    delay(1000);
    answer("Progress is built from small and steady steps.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(7))
  {
    int randommistake = random(0, 3);
    int randommistakerecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Mistakes are part of learning and growth.");
    delay(1000);
    answer("Every experience can teach us something valuable.");
    delay(1000);
    answer("Reflect on what you learned and move forward stronger.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(happy);
    idle = 0;
  }

  if (asr.isDetectCmdID(8))
  {
    int randomnocontrol = random(0, 3);
    int randomnocontrolrecom = random(0, 3);

    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Some things are outside our control.");
    delay(1000);
    answer("Peace comes when we accept this and focus on our actions.");
    delay(1000);
    answer("Direct your energy to what you can influence.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(9))
  {
    int randomunmotivated = random(0, 3);
    int randomunmotivatedrecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Motivation can come and go.");
    delay(1000);
    answer("Discipline means taking action even when motivation is quiet.");
    delay(1000);
    answer("Start with one small task and build momentum.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(think);
    idle = 0;
  }

  if (asr.isDetectCmdID(10))
  {
    int randomwisdom = random(0, 3);
    int randomwisdomrecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Here is a piece of wisdom for today.");
    delay(1000);
    answer("You have control over your thoughts and actions.");
    delay(1000);
    answer("Focus on those, and let the rest unfold naturally.");
    delay(1000);
    answer("Is there anything else you want to talk about?");
    philosopher(happy);
    idle = 0;
  }

  if (asr.isDetectCmdID(11))
  {
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

  if (asr.isDetectCmdID(12))
  {
    int randomscare = random(0, 3);
    int randomscarerecom = random(0, 3);
    philosopher(think);
    answer("Thinking...");
    delay(1200);
    philosopher(talking);
    answer("Here is some music for you to relax. It's one of my favorites, please enjoy. If you want to talk to me again, please restart the device.");
    delay(1000);
    philosopher(happy);
    idle = 0;
  }
  if (idle > 30)
  {
    sleepingstate = true;
    philosopher(sleeping);
    answer("Zzz...");
  }
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
  asr.addASRCommand(8, "I cannot control this");
  asr.addASRCommand(9, "I feel unmotivated");
  asr.addASRCommand(10, "Give me wisdom");
  asr.addASRCommand(11, "Play music");
  asr.addASRCommand(12, "I am scared");
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
