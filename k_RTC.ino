#ifdef USE_RTC

void initRTC()
{
  rtc.begin();
  if (rtc.lostPower()) {
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

#else

void initRTC()
{
}

#endif /* USE_RTC */
