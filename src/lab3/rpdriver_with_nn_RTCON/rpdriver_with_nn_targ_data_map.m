  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rpdriver_with_nn_P)
    ;%
      section.nData     = 66;
      section.data(66)  = dumData; %prealloc
      
	  ;% rpdriver_with_nn_P.mapminmax_xmax
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_xmax
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rpdriver_with_nn_P.mapminmax_xmax_o
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_xmax_g
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% rpdriver_with_nn_P.mapminmax_xmin
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_xmin
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rpdriver_with_nn_P.mapminmax_xmin_f
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_xmin_e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% rpdriver_with_nn_P.mapminmax_ymax
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_ymax
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% rpdriver_with_nn_P.mapminmax_ymax_h
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_ymax_j
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rpdriver_with_nn_P.mapminmax_ymin
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_ymin
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rpdriver_with_nn_P.mapminmax_ymin_n
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rpdriver_with_nn_P.mapminmax_reverse_ymin_j
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rpdriver_with_nn_P.DC_Ctrl2_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rpdriver_with_nn_P.Saturation_UpperSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rpdriver_with_nn_P.Saturation_LowerSat
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rpdriver_with_nn_P.Gain1_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rpdriver_with_nn_P.DC_Ctrl1_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rpdriver_with_nn_P.Normal_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rpdriver_with_nn_P.Reset_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% rpdriver_with_nn_P.SFunction_P1_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% rpdriver_with_nn_P.SFunction_P1
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 29;
	
	  ;% rpdriver_with_nn_P.SFunction_P2_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 30;
	
	  ;% rpdriver_with_nn_P.SFunction_P2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 32;
	
	  ;% rpdriver_with_nn_P.PendulumConverttorad_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 33;
	
	  ;% rpdriver_with_nn_P.Constant_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 34;
	
	  ;% rpdriver_with_nn_P.Memory2_InitialCondition
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 35;
	
	  ;% rpdriver_with_nn_P.rad2rads_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 36;
	
	  ;% rpdriver_with_nn_P.Memory_InitialCondition
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 37;
	
	  ;% rpdriver_with_nn_P.Gain1_Gain_h
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 38;
	
	  ;% rpdriver_with_nn_P.DCConverttorad_Gain
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 39;
	
	  ;% rpdriver_with_nn_P.Memory1_InitialCondition
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 40;
	
	  ;% rpdriver_with_nn_P.rad2RPM_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 41;
	
	  ;% rpdriver_with_nn_P.DCConverttoA1_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 42;
	
	  ;% rpdriver_with_nn_P.Gain3_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 43;
	
	  ;% rpdriver_with_nn_P.IW211_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 44;
	
	  ;% rpdriver_with_nn_P.IW111_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 48;
	
	  ;% rpdriver_with_nn_P.Memory_InitialCondition_j
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 50;
	
	  ;% rpdriver_with_nn_P.Memory1_InitialCondition_f
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 51;
	
	  ;% rpdriver_with_nn_P.IW112_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 52;
	
	  ;% rpdriver_with_nn_P.IW113_Value
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 54;
	
	  ;% rpdriver_with_nn_P.IW114_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 56;
	
	  ;% rpdriver_with_nn_P.b1_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 58;
	
	  ;% rpdriver_with_nn_P.Gain_Gain
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 62;
	
	  ;% rpdriver_with_nn_P.one_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 63;
	
	  ;% rpdriver_with_nn_P.Gain1_Gain_g
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 64;
	
	  ;% rpdriver_with_nn_P.one1_Value
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 65;
	
	  ;% rpdriver_with_nn_P.b2_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 66;
	
	  ;% rpdriver_with_nn_P.IW211_Value_j
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 67;
	
	  ;% rpdriver_with_nn_P.IW111_Value_g
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 69;
	
	  ;% rpdriver_with_nn_P.IW112_Value_j
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 71;
	
	  ;% rpdriver_with_nn_P.b1_Value_n
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 73;
	
	  ;% rpdriver_with_nn_P.Gain_Gain_i
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 75;
	
	  ;% rpdriver_with_nn_P.one_Value_g
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 76;
	
	  ;% rpdriver_with_nn_P.Gain1_Gain_hd
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 77;
	
	  ;% rpdriver_with_nn_P.one1_Value_m
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 78;
	
	  ;% rpdriver_with_nn_P.b2_Value_m
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 79;
	
	  ;% rpdriver_with_nn_P.Gain_Gain_d
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 80;
	
	  ;% rpdriver_with_nn_P.Gain2_Gain
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 82;
	
	  ;% rpdriver_with_nn_P.Prescaler_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 83;
	
	  ;% rpdriver_with_nn_P.Saturation_UpperSat_h
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 84;
	
	  ;% rpdriver_with_nn_P.Saturation_LowerSat_f
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 85;
	
	  ;% rpdriver_with_nn_P.ThermFlag_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 86;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rpdriver_with_nn_P.ResetEncoders2_CurrentSetting
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rpdriver_with_nn_P.ResetEncoders1_CurrentSetting
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rpdriver_with_nn_P.ResetEncoders_CurrentSetting
	  section.data(3).logicalSrcIdx = 68;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rpdriver_with_nn_B)
    ;%
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% rpdriver_with_nn_B.SFunction_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rpdriver_with_nn_B.SFunction_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rpdriver_with_nn_B.SFunction_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rpdriver_with_nn_B.SFunction_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rpdriver_with_nn_B.SFunction_o5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rpdriver_with_nn_B.SFunction_o6
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rpdriver_with_nn_B.SFunction_o7
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rpdriver_with_nn_B.PendulumAnglerad
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rpdriver_with_nn_B.PendPos_ZeroDown
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rpdriver_with_nn_B.PendPos_ZeroUp
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rpdriver_with_nn_B.Periodms
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rpdriver_with_nn_B.PendulumVelrads
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% rpdriver_with_nn_B.DCAnglerad
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
	  ;% rpdriver_with_nn_B.DCVelrads
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 14;
	
	  ;% rpdriver_with_nn_B.DCConverttoA1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% rpdriver_with_nn_B.Control
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 16;
	
	  ;% rpdriver_with_nn_B.Addminx
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 17;
	
	  ;% rpdriver_with_nn_B.Addminx_f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 18;
	
	  ;% rpdriver_with_nn_B.Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% rpdriver_with_nn_B.Prescaler
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% rpdriver_with_nn_B.Saturation
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
	  ;% rpdriver_with_nn_B.ThermFlag
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rpdriver_with_nn_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rpdriver_with_nn_DW.Memory2_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rpdriver_with_nn_DW.Memory_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rpdriver_with_nn_DW.Memory1_PreviousInput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rpdriver_with_nn_DW.Memory_PreviousInput_i
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rpdriver_with_nn_DW.Memory1_PreviousInput_l
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rpdriver_with_nn_DW.PlotState_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rpdriver_with_nn_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3421656560;
  targMap.checksum1 = 1373510660;
  targMap.checksum2 = 2302455066;
  targMap.checksum3 = 1045884951;

