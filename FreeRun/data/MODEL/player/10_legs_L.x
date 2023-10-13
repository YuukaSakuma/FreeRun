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
 72;
 -1.85098;-26.54702;1.85098;,
 0.00000;-26.54702;2.61768;,
 0.00000;-24.33999;2.98550;,
 -2.11106;-24.33999;2.11106;,
 1.85098;-26.54702;1.85098;,
 2.11106;-24.33999;2.11106;,
 2.61768;-26.54702;-0.00000;,
 2.98550;-24.33999;-0.00000;,
 1.85098;-26.54702;-1.85098;,
 2.11106;-24.33999;-2.11106;,
 0.00000;-26.54702;-2.61768;,
 0.00000;-24.33999;-2.98550;,
 -1.85098;-26.54702;-1.85098;,
 -2.11106;-24.33999;-2.11106;,
 -2.61768;-26.54702;0.00000;,
 -2.98550;-24.33999;0.00000;,
 -1.85098;-26.54702;1.85098;,
 -2.11106;-24.33999;2.11106;,
 -0.00000;-28.08618;1.97280;,
 -1.39498;-28.08618;1.39498;,
 0.00000;-29.40663;0.00000;,
 1.39498;-28.08618;1.39498;,
 1.97280;-28.08618;-0.00000;,
 1.39498;-28.08618;-1.39498;,
 0.00000;-28.08618;-1.97280;,
 -1.39498;-28.08618;-1.39498;,
 -1.97280;-28.08618;0.00000;,
 -1.87764;2.71341;1.87764;,
 0.00000;2.71341;2.65539;,
 0.00000;3.87799;0.00000;,
 1.87764;2.71341;1.87764;,
 2.65539;2.71341;0.00000;,
 1.87764;2.71341;-1.87764;,
 0.00000;2.71341;-2.65539;,
 -1.87764;2.71341;-1.87764;,
 -2.65539;2.71341;0.00000;,
 -1.39498;-28.08618;1.39498;,
 -0.00000;-28.08618;1.97280;,
 1.39498;-28.08618;1.39498;,
 1.97280;-28.08618;-0.00000;,
 1.39498;-28.08618;-1.39498;,
 0.00000;-28.08618;-1.97280;,
 -1.39498;-28.08618;-1.39498;,
 -1.97280;-28.08618;0.00000;,
 -1.39498;-28.08618;1.39498;,
 -2.77501;0.01922;2.77501;,
 -3.92446;0.01922;0.00000;,
 -2.77501;0.01922;-2.77501;,
 0.00000;0.01922;-3.92446;,
 2.77501;0.01922;-2.77501;,
 3.92446;0.01922;0.00000;,
 2.77501;0.01922;2.77501;,
 0.00000;0.01922;3.92446;,
 -2.77501;0.01922;2.77501;,
 -2.44018;1.54154;2.44018;,
 -3.45094;1.54154;0.00000;,
 -2.44018;1.54154;-2.44018;,
 0.00000;1.54154;-3.45094;,
 2.44018;1.54154;-2.44018;,
 3.45094;1.54154;0.00000;,
 2.44018;1.54154;2.44018;,
 0.00000;1.54154;3.45094;,
 -2.44018;1.54154;2.44018;,
 -1.87764;2.71341;1.87764;,
 -2.65539;2.71341;0.00000;,
 -1.87764;2.71341;-1.87764;,
 0.00000;2.71341;-2.65539;,
 1.87764;2.71341;-1.87764;,
 2.65539;2.71341;0.00000;,
 1.87764;2.71341;1.87764;,
 0.00000;2.71341;2.65539;,
 -1.87764;2.71341;1.87764;;
 
 56;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 3;18,19,20;,
 3;21,18,20;,
 3;22,21,20;,
 3;23,22,20;,
 3;24,23,20;,
 3;25,24,20;,
 3;26,25,20;,
 3;19,26,20;,
 3;27,28,29;,
 3;28,30,29;,
 3;30,31,29;,
 3;31,32,29;,
 3;32,33,29;,
 3;33,34,29;,
 3;34,35,29;,
 3;35,27,29;,
 4;36,37,1,0;,
 4;37,38,4,1;,
 4;38,39,6,4;,
 4;39,40,8,6;,
 4;40,41,10,8;,
 4;41,42,12,10;,
 4;42,43,14,12;,
 4;43,44,16,14;,
 4;15,17,45,46;,
 4;13,15,46,47;,
 4;11,13,47,48;,
 4;9,11,48,49;,
 4;7,9,49,50;,
 4;5,7,50,51;,
 4;2,5,51,52;,
 4;3,2,52,53;,
 4;46,45,54,55;,
 4;47,46,55,56;,
 4;48,47,56,57;,
 4;49,48,57,58;,
 4;50,49,58,59;,
 4;51,50,59,60;,
 4;52,51,60,61;,
 4;53,52,61,62;,
 4;55,54,63,64;,
 4;56,55,64,65;,
 4;57,56,65,66;,
 4;58,57,66,67;,
 4;59,58,67,68;,
 4;60,59,68,69;,
 4;61,60,69,70;,
 4;62,61,70,71;;
 
 MeshMaterialList {
  1;
  56;
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
    "data\\TEXTURE\\player01.png";
   }
  }
 }
 MeshNormals {
  50;
  -0.543001;-0.640547;0.543001;,
  0.000000;-0.640547;0.767919;,
  0.543001;-0.640547;0.543001;,
  0.767919;-0.640547;-0.000000;,
  0.543001;-0.640547;-0.543001;,
  0.000000;-0.640547;-0.767919;,
  -0.543001;-0.640547;-0.543001;,
  -0.767919;-0.640547;0.000000;,
  -0.448910;0.772632;0.448910;,
  0.000000;0.772633;0.634853;,
  0.448910;0.772632;0.448910;,
  0.634853;0.772633;0.000000;,
  0.448910;0.772632;-0.448910;,
  0.000000;0.772633;-0.634853;,
  -0.448910;0.772632;-0.448910;,
  -0.634853;0.772633;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  -0.679279;-0.277776;0.679279;,
  0.000000;-0.277776;0.960646;,
  0.679279;-0.277776;0.679279;,
  0.960646;-0.277776;-0.000000;,
  0.679279;-0.277776;-0.679279;,
  0.000000;-0.277776;-0.960646;,
  -0.679279;-0.277776;-0.679279;,
  -0.960646;-0.277776;0.000000;,
  -0.703439;-0.101716;0.703439;,
  -0.994813;-0.101716;0.000000;,
  -0.703439;-0.101716;-0.703439;,
  0.000000;-0.101716;-0.994813;,
  0.703439;-0.101716;-0.703439;,
  0.994813;-0.101716;-0.000000;,
  0.703439;-0.101716;0.703439;,
  0.000000;-0.101716;0.994813;,
  -0.700949;0.131684;0.700949;,
  -0.991292;0.131684;0.000000;,
  -0.700949;0.131684;-0.700949;,
  0.000000;0.131684;-0.991292;,
  0.700949;0.131684;-0.700949;,
  0.991292;0.131684;0.000000;,
  0.700949;0.131684;0.700949;,
  0.000000;0.131684;0.991292;,
  -0.636633;0.435198;0.636633;,
  -0.900334;0.435199;0.000000;,
  -0.636633;0.435198;-0.636633;,
  0.000000;0.435199;-0.900334;,
  0.636633;0.435198;-0.636633;,
  0.900334;0.435199;0.000000;,
  0.636633;0.435198;0.636633;,
  0.000000;0.435199;0.900334;;
  56;
  4;18,19,33,26;,
  4;19,20,32,33;,
  4;20,21,31,32;,
  4;21,22,30,31;,
  4;22,23,29,30;,
  4;23,24,28,29;,
  4;24,25,27,28;,
  4;25,18,26,27;,
  3;1,0,16;,
  3;2,1,16;,
  3;3,2,16;,
  3;4,3,16;,
  3;5,4,16;,
  3;6,5,16;,
  3;7,6,16;,
  3;0,7,16;,
  3;8,9,17;,
  3;9,10,17;,
  3;10,11,17;,
  3;11,12,17;,
  3;12,13,17;,
  3;13,14,17;,
  3;14,15,17;,
  3;15,8,17;,
  4;0,1,19,18;,
  4;1,2,20,19;,
  4;2,3,21,20;,
  4;3,4,22,21;,
  4;4,5,23,22;,
  4;5,6,24,23;,
  4;6,7,25,24;,
  4;7,0,18,25;,
  4;27,26,34,35;,
  4;28,27,35,36;,
  4;29,28,36,37;,
  4;30,29,37,38;,
  4;31,30,38,39;,
  4;32,31,39,40;,
  4;33,32,40,41;,
  4;26,33,41,34;,
  4;35,34,42,43;,
  4;36,35,43,44;,
  4;37,36,44,45;,
  4;38,37,45,46;,
  4;39,38,46,47;,
  4;40,39,47,48;,
  4;41,40,48,49;,
  4;34,41,49,42;,
  4;43,42,8,15;,
  4;44,43,15,14;,
  4;45,44,14,13;,
  4;46,45,13,12;,
  4;47,46,12,11;,
  4;48,47,11,10;,
  4;49,48,10,9;,
  4;42,49,9,8;;
 }
 MeshTextureCoords {
  72;
  0.031442;0.874069;,
  0.040161;0.874069;,
  0.040161;0.855768;,
  0.031442;0.855768;,
  0.048880;0.874069;,
  0.048880;0.855768;,
  0.057599;0.874069;,
  0.057599;0.855768;,
  0.066317;0.874069;,
  0.066317;0.855768;,
  0.075036;0.874069;,
  0.075036;0.855768;,
  0.083755;0.874069;,
  0.083755;0.855768;,
  0.092474;0.874069;,
  0.092474;0.855768;,
  0.101193;0.874069;,
  0.101193;0.855768;,
  0.066317;0.994190;,
  0.097143;0.981422;,
  0.066317;0.952340;,
  0.035492;0.981422;,
  0.022723;0.950596;,
  0.035492;0.919771;,
  0.066317;0.907002;,
  0.097143;0.919771;,
  0.109911;0.950596;,
  0.097143;0.727957;,
  0.066317;0.715189;,
  0.066317;0.760526;,
  0.035492;0.727957;,
  0.022723;0.758783;,
  0.035492;0.789608;,
  0.066317;0.802377;,
  0.097143;0.789608;,
  0.109911;0.758783;,
  0.031442;0.907002;,
  0.040161;0.907002;,
  0.048880;0.907002;,
  0.057599;0.907002;,
  0.066317;0.907002;,
  0.075036;0.907002;,
  0.083755;0.907002;,
  0.092474;0.907002;,
  0.101193;0.907002;,
  0.101193;0.831568;,
  0.092474;0.831568;,
  0.083755;0.831568;,
  0.075036;0.831568;,
  0.066317;0.831568;,
  0.057599;0.831568;,
  0.048880;0.831568;,
  0.040161;0.831568;,
  0.031442;0.831568;,
  0.101193;0.816548;,
  0.092474;0.816548;,
  0.083755;0.816548;,
  0.075036;0.816548;,
  0.066317;0.816548;,
  0.057599;0.816548;,
  0.048880;0.816548;,
  0.040161;0.816548;,
  0.031442;0.816548;,
  0.101193;0.802114;,
  0.092474;0.802114;,
  0.083755;0.802114;,
  0.075036;0.802114;,
  0.066317;0.802114;,
  0.057599;0.802114;,
  0.048880;0.802114;,
  0.040161;0.802114;,
  0.031442;0.802114;;
 }
}