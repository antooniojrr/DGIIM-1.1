<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-27,1115,1103,1,0,46>
  <Grid=10,10,1>
  <DataSet=Circuito 1.dat>
  <DataDisplay=Circuito 1.dpl>
  <OpenDisplay=1>
  <Script=Circuito 1.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Título>
  <FrameText1=Dibujado por:>
  <FrameText2=Fecha:>
  <FrameText3=Revisión:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <Vdc V 1 220 310 18 -26 0 1 "10" 1>
  <IProbe I1 1 370 200 -26 16 0 0>
  <IProbe I2 1 480 330 -48 -26 0 3>
  <VProbe V1 1 310 140 28 -31 0 0>
  <R R1 1 310 200 -26 15 0 0 "2200" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R2 1 480 270 15 -26 0 1 "4700" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <.DC Divisor_Tension 1 560 100 0 47 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <VProbe V2 1 600 270 -16 28 0 3>
</Components>
<Wires>
  <220 200 220 280 "" 0 0 0 "">
  <220 200 280 200 "" 0 0 0 "">
  <400 200 480 200 "" 0 0 0 "">
  <480 200 480 240 "" 0 0 0 "">
  <220 340 220 390 "" 0 0 0 "">
  <220 390 480 390 "" 0 0 0 "">
  <480 360 480 390 "" 0 0 0 "">
  <280 160 280 200 "" 0 0 0 "">
  <280 160 300 160 "" 0 0 0 "">
  <320 160 340 160 "" 0 0 0 "">
  <340 160 340 200 "" 0 0 0 "">
  <480 300 580 300 "" 0 0 0 "">
  <580 280 580 300 "" 0 0 0 "">
  <480 240 580 240 "" 0 0 0 "">
  <580 240 580 260 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Tab 700 307 375 97 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"I1.I" #0000ff 0 3 1 0 0>
	<"I2.I" #0000ff 0 3 1 0 0>
	<"V1.V" #0000ff 0 3 1 0 0>
	<"V2.V" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
</Paintings>
