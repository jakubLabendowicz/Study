<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-79,1241,740,1,0,120>
  <Grid=10,10,1>
  <DataSet=eeeeee.dat>
  <DataDisplay=eeeeee.dpl>
  <OpenDisplay=1>
  <Script=eeeeee.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <Vac V1 1 120 330 18 -26 0 1 "55" 1 "1 GHz" 0 "0" 0 "0" 0>
  <IProbe I_A 1 210 240 -26 16 0 0>
  <R RL1 1 620 -20 -26 15 0 0 "89" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R RL2 1 900 -20 -26 15 0 0 "83" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <MUT Tr1 1 760 10 -29 38 0 0 "0.732 H" 0 "0.792 H" 0 "k_L" 0>
  <VProbe U_V 1 320 290 -16 28 0 3>
  <GND * 1 120 410 0 0 0 0>
  <VProbe U_2 1 870 140 28 -31 0 0>
  <Eqn Eqn1 1 230 -30 -42 18 0 0 "k_L=(8^3)/((8^2+(L+3)^2)^(3/2))" 1 "yes" 0>
  <.AC AC1 1 1010 -50 0 47 0 0 "const" 1 "1 GHz" 0 "10 GHz" 0 "[50 Hz]" 1 "no" 0>
  <Eqn Eqn2 1 1060 140 -42 18 0 0 "cos=P/abs(S)" 1 "P=real(S)" 1 "S=U_V.v*conj(I_A.i)" 1 "yes" 0>
  <.SW SW1 1 1020 350 0 79 0 0 "AC1" 1 "lin" 1 "L" 1 "0" 1 "18" 1 "19" 1>
</Components>
<Wires>
  <120 240 120 300 "" 0 0 0 "">
  <120 240 180 240 "" 0 0 0 "">
  <650 -20 730 -20 "" 0 0 0 "">
  <540 -20 590 -20 "" 0 0 0 "">
  <790 -20 870 -20 "" 0 0 0 "">
  <240 240 300 240 "" 0 0 0 "">
  <300 240 300 280 "" 0 0 0 "">
  <120 410 300 410 "" 0 0 0 "">
  <120 360 120 410 "" 0 0 0 "">
  <300 300 300 410 "" 0 0 0 "">
  <300 240 540 240 "" 0 0 0 "">
  <540 -20 540 240 "" 0 0 0 "">
  <930 -20 930 180 "" 0 0 0 "">
  <880 180 930 180 "" 0 0 0 "">
  <880 160 880 180 "" 0 0 0 "">
  <860 160 860 180 "" 0 0 0 "">
  <790 180 860 180 "" 0 0 0 "">
  <790 40 790 180 "" 0 0 0 "">
  <730 40 730 410 "" 0 0 0 "">
  <300 410 730 410 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Tab 110 660 857 203 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 19 315 0 225 "" "" "">
	<"U_V.v" #0000ff 0 3 1 0 0>
	<"I_A.i" #0000ff 0 3 1 0 0>
	<"P" #0000ff 0 3 1 0 0>
	<"S" #0000ff 0 3 1 0 0>
	<"cos" #0000ff 0 3 1 0 0>
	<"U_2.v" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
  <Text 810 110 12 #000000 0 "K2\n">
  <Text 680 100 12 #000000 0 "K1\n">
</Paintings>
