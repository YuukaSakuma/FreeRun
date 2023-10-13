xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 74;
 -2.46964;-0.18938;8.78408;,
 0.00000;0.78592;9.09271;,
 0.00000;4.20572;8.09981;,
 -4.56330;2.40362;7.52953;,
 2.46964;-0.18938;8.78408;,
 4.56330;2.40362;7.52953;,
 3.49260;-2.54394;8.03897;,
 6.45348;-1.94704;6.15276;,
 3.49260;-2.54394;8.03897;,
 2.46964;-4.89850;7.29387;,
 4.56330;-6.29770;4.77600;,
 6.45348;-1.94704;6.15276;,
 -0.00000;-5.87378;6.98524;,
 -0.00000;-8.09981;4.20572;,
 -2.46964;-4.89850;7.29387;,
 -4.56330;-6.29770;4.77600;,
 -3.49260;-2.54394;8.03897;,
 -6.45349;-1.94704;6.15276;,
 -3.49260;-2.54394;8.03897;,
 -6.45349;-1.94704;6.15276;,
 0.00000;6.98524;5.87379;,
 -5.96224;4.63067;5.12868;,
 5.96224;4.63067;5.12868;,
 8.43188;-1.05373;3.32985;,
 5.96224;-6.73814;1.53102;,
 8.43188;-1.05373;3.32985;,
 -0.00000;-9.09271;0.78592;,
 -5.96224;-6.73814;1.53102;,
 -8.43188;-1.05373;3.32985;,
 -8.43188;-1.05373;3.32985;,
 0.00000;8.70132;2.75353;,
 -6.45348;6.15276;1.94704;,
 6.45348;6.15276;1.94704;,
 9.12661;0.00000;0.00000;,
 6.45348;-6.15276;-1.94704;,
 9.12661;0.00000;0.00000;,
 0.00000;-8.70132;-2.75353;,
 -6.45349;-6.15276;-1.94704;,
 -9.12661;0.00000;0.00000;,
 -9.12661;0.00000;0.00000;,
 0.00000;9.09272;-0.78591;,
 -5.96224;6.73814;-1.53102;,
 5.96224;6.73814;-1.53102;,
 8.43188;1.05373;-3.32985;,
 5.96224;-4.63067;-5.12868;,
 8.43188;1.05373;-3.32985;,
 0.00000;-6.98524;-5.87379;,
 -5.96224;-4.63067;-5.12868;,
 -8.43188;1.05373;-3.32985;,
 -8.43188;1.05373;-3.32985;,
 0.00000;8.09981;-4.20572;,
 -4.56330;6.29770;-4.77600;,
 4.56330;6.29770;-4.77600;,
 6.45348;1.94705;-6.15276;,
 4.56330;-2.40362;-7.52953;,
 6.45348;1.94705;-6.15276;,
 0.00000;-4.20572;-8.09981;,
 -4.56330;-2.40362;-7.52953;,
 -6.45349;1.94705;-6.15276;,
 -6.45349;1.94705;-6.15276;,
 0.00000;5.87379;-6.98524;,
 -2.46964;4.89850;-7.29387;,
 2.46964;4.89850;-7.29387;,
 3.49260;2.54394;-8.03897;,
 2.46964;0.18938;-8.78407;,
 3.49260;2.54394;-8.03897;,
 0.00000;-0.78591;-9.09271;,
 -2.46964;0.18938;-8.78407;,
 -3.49260;2.54394;-8.03897;,
 -3.49260;2.54394;-8.03897;,
 -0.00000;-2.75354;8.70132;,
 -0.00000;-2.75354;8.70132;,
 0.00000;2.75354;-8.70132;,
 0.00000;2.75354;-8.70132;;
 
 64;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;18,0,3,19;,
 4;3,2,20,21;,
 4;2,5,22,20;,
 4;5,7,23,22;,
 4;11,10,24,25;,
 4;10,13,26,24;,
 4;13,15,27,26;,
 4;15,17,28,27;,
 4;19,3,21,29;,
 4;21,20,30,31;,
 4;20,22,32,30;,
 4;22,23,33,32;,
 4;25,24,34,35;,
 4;24,26,36,34;,
 4;26,27,37,36;,
 4;27,28,38,37;,
 4;29,21,31,39;,
 4;31,30,40,41;,
 4;30,32,42,40;,
 4;32,33,43,42;,
 4;35,34,44,45;,
 4;34,36,46,44;,
 4;36,37,47,46;,
 4;37,38,48,47;,
 4;39,31,41,49;,
 4;41,40,50,51;,
 4;40,42,52,50;,
 4;42,43,53,52;,
 4;45,44,54,55;,
 4;44,46,56,54;,
 4;46,47,57,56;,
 4;47,48,58,57;,
 4;49,41,51,59;,
 4;51,50,60,61;,
 4;50,52,62,60;,
 4;52,53,63,62;,
 4;55,54,64,65;,
 4;54,56,66,64;,
 4;56,57,67,66;,
 4;57,58,68,67;,
 4;59,51,61,69;,
 3;1,0,70;,
 3;4,1,70;,
 3;6,4,70;,
 3;9,8,71;,
 3;12,9,71;,
 3;14,12,71;,
 3;16,14,71;,
 3;0,18,70;,
 3;61,60,72;,
 3;60,62,72;,
 3;62,63,72;,
 3;65,64,73;,
 3;64,66,73;,
 3;66,67,73;,
 3;67,68,73;,
 3;69,61,72;;
 
 MeshMaterialList {
  1;
  64;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\enemy01_00.png";
   }
  }
 }
 MeshNormals {
  58;
  -0.269133;-0.022406;0.962842;,
  0.000000;0.083878;0.996476;,
  0.269133;-0.022406;0.962842;,
  0.380612;-0.278997;0.881644;,
  0.269133;-0.535588;0.800446;,
  0.000000;-0.641872;0.766812;,
  -0.269133;-0.535588;0.800446;,
  -0.380612;-0.278997;0.881644;,
  -0.498494;0.261287;0.826579;,
  0.000000;0.458148;0.888876;,
  0.498495;0.261287;0.826579;,
  0.704977;-0.213978;0.676181;,
  0.498494;-0.689242;0.525784;,
  0.000000;-0.886104;0.463487;,
  -0.498494;-0.689243;0.525783;,
  -0.704977;-0.213978;0.676181;,
  -0.652733;0.506296;0.563564;,
  0.000000;0.764068;0.645136;,
  0.652733;0.506296;0.563564;,
  0.923104;-0.116021;0.366632;,
  0.652733;-0.738337;0.169699;,
  0.000000;-0.996109;0.088127;,
  -0.652733;-0.738337;0.169699;,
  -0.923104;-0.116020;0.366632;,
  -0.707107;0.674156;0.213338;,
  0.000000;0.953401;0.301706;,
  0.707107;0.674156;0.213338;,
  1.000000;0.000000;0.000000;,
  0.707107;-0.674157;-0.213337;,
  0.000000;-0.953402;-0.301705;,
  -0.707107;-0.674157;-0.213337;,
  -1.000000;0.000000;0.000000;,
  -0.652733;0.738337;-0.169699;,
  0.000000;0.996109;-0.088127;,
  0.652733;0.738337;-0.169699;,
  0.923104;0.116021;-0.366632;,
  0.652733;-0.506296;-0.563564;,
  0.000000;-0.764068;-0.645136;,
  -0.652733;-0.506296;-0.563564;,
  -0.923104;0.116021;-0.366631;,
  -0.498494;0.689243;-0.525783;,
  0.000000;0.886104;-0.463487;,
  0.498494;0.689243;-0.525784;,
  0.704977;0.213978;-0.676181;,
  0.498494;-0.261287;-0.826579;,
  0.000000;-0.458148;-0.888876;,
  -0.498494;-0.261287;-0.826579;,
  -0.704977;0.213978;-0.676181;,
  -0.269132;0.535589;-0.800445;,
  0.000000;0.641873;-0.766811;,
  0.269132;0.535589;-0.800445;,
  0.380611;0.278995;-0.881644;,
  0.269133;0.022404;-0.962842;,
  0.000000;-0.083878;-0.996476;,
  -0.269133;0.022404;-0.962842;,
  -0.380611;0.278996;-0.881644;,
  0.000000;-0.301704;0.953402;,
  -0.000000;0.301704;-0.953402;;
  64;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,16,24,31;,
  4;24,25,33,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,24,32,39;,
  4;32,33,41,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,32,40,47;,
  4;40,41,49,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,40,48,55;,
  3;1,0,56;,
  3;2,1,56;,
  3;3,2,56;,
  3;4,3,56;,
  3;5,4,56;,
  3;6,5,56;,
  3;7,6,56;,
  3;0,7,56;,
  3;48,49,57;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,48,57;;
 }
 MeshTextureCoords {
  74;
  0.236700;0.648900;,
  0.191220;0.643060;,
  0.191220;0.661820;,
  0.275250;0.672600;,
  0.145740;0.648900;,
  0.107180;0.672600;,
  0.126900;0.662970;,
  0.072370;0.698600;,
  0.504600;0.671130;,
  0.523000;0.684880;,
  0.485340;0.731340;,
  0.451340;0.705940;,
  0.567420;0.690580;,
  0.567420;0.741860;,
  0.611850;0.684880;,
  0.649510;0.731340;,
  0.630250;0.671130;,
  0.683510;0.705940;,
  0.255540;0.662970;,
  0.310060;0.698600;,
  0.191220;0.703870;,
  0.301020;0.717950;,
  0.081420;0.717950;,
  0.035930;0.751930;,
  0.460170;0.791220;,
  0.415750;0.758030;,
  0.567420;0.804970;,
  0.674670;0.791220;,
  0.719100;0.758030;,
  0.346500;0.751930;,
  0.191220;0.762820;,
  0.310060;0.778060;,
  0.072370;0.778060;,
  0.023140;0.814840;,
  0.451340;0.855400;,
  0.403250;0.819470;,
  0.567420;0.870280;,
  0.683510;0.855400;,
  0.731590;0.819470;,
  0.359290;0.814840;,
  0.191220;0.829680;,
  0.301020;0.843760;,
  0.081420;0.843760;,
  0.035930;0.877740;,
  0.460170;0.914100;,
  0.415750;0.880910;,
  0.567420;0.927850;,
  0.674670;0.914100;,
  0.719100;0.880910;,
  0.346500;0.877740;,
  0.191220;0.894290;,
  0.275250;0.905060;,
  0.107180;0.905060;,
  0.072370;0.931070;,
  0.485340;0.958410;,
  0.451340;0.933000;,
  0.567420;0.968930;,
  0.649510;0.958410;,
  0.683510;0.933000;,
  0.310060;0.931070;,
  0.191220;0.946800;,
  0.236700;0.952630;,
  0.145740;0.952630;,
  0.126900;0.966700;,
  0.523000;0.981550;,
  0.504600;0.967810;,
  0.567420;0.987250;,
  0.611850;0.981550;,
  0.630250;0.967810;,
  0.255540;0.966700;,
  0.191220;0.650460;,
  0.567420;0.653520;,
  0.191220;0.979220;,
  0.567420;0.980030;;
 }
}
