<Qucs Schematic 0.0.19>
<Properties>
  <View=0,25,1471,1289,1,0,420>
  <Grid=10,10,1>
  <DataSet=Bode.dat>
  <DataDisplay=Bode.dpl>
  <OpenDisplay=1>
  <Script=Bode.m>
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
  <L L1 1 510 200 -26 10 0 0 "25 mH" 1 "" 0>
  <R R1 1 510 300 -26 15 0 0 "5 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Vac Vi 1 380 390 18 -26 0 1 "1 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <R R2 1 640 390 -113 -26 1 1 "5 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <VProbe Vin 1 310 320 -55 -31 1 2>
  <VProbe Vout 1 510 80 28 -31 0 0>
  <Eqn Tdb_out 1 840 90 -39 18 0 0 "Tdb_out=20*log10(abs(Vout.v)/abs(Vin.v))" 1 "yes" 0>
  <Eqn ArgT_out 1 880 210 -39 18 0 0 "ArgT_out=arg(Vout.v) - arg(Vin.v)" 1 "yes" 0>
  <.AC AC1 1 80 80 0 47 0 0 "log" 1 "1 mHz" 1 "10 MHz" 1 "30" 1 "no" 0>
</Components>
<Wires>
  <380 200 380 300 "" 0 0 0 "">
  <380 200 480 200 "" 0 0 0 "">
  <380 300 380 360 "" 0 0 0 "">
  <380 300 480 300 "" 0 0 0 "">
  <540 300 640 300 "" 0 0 0 "">
  <640 300 640 360 "" 0 0 0 "">
  <640 420 640 460 "" 0 0 0 "">
  <380 460 640 460 "" 0 0 0 "">
  <380 420 380 460 "" 0 0 0 "">
  <540 200 640 200 "" 0 0 0 "">
  <640 200 640 300 "" 0 0 0 "">
  <380 100 500 100 "" 0 0 0 "">
  <380 100 380 200 "" 0 0 0 "">
  <520 100 640 100 "" 0 0 0 "">
  <640 100 640 200 "" 0 0 0 "">
  <300 340 300 420 "" 0 0 0 "">
  <300 420 380 420 "" 0 0 0 "">
  <320 340 320 360 "" 0 0 0 "">
  <320 360 380 360 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 210 806 485 296 3 #c0c0c0 1 10 1 1 1 1e+07 1 -100 20 2.38315 1 -1 0.5 1 315 0 225 "" "20log|T| (dB)" "">
	<"Tdb_out" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 210 1172 491 302 3 #c0c0c0 1 10 1 0 2e+06 1e+07 1 -0.155323 1 2 1 -1 1 1 315 0 225 "" "" "">
	<"ArgT_out" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
