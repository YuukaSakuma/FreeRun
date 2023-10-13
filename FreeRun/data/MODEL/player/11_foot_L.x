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
 34;
 -2.79172;-0.78989;2.92431;,
 0.00000;-0.78989;4.40991;,
 0.00000;0.02359;2.84494;,
 -2.20044;0.02359;1.97986;,
 2.79173;-0.78989;2.92431;,
 2.20044;0.02359;1.97986;,
 3.94810;-0.78989;-0.66225;,
 3.11189;0.02359;-0.10863;,
 2.79173;-0.78989;-4.24880;,
 2.20044;0.02359;-2.19711;,
 0.00000;-0.78989;-5.34247;,
 0.00000;0.02359;-3.06221;,
 -2.79173;-0.78989;-4.24880;,
 -2.20044;0.02359;-2.19711;,
 -3.94809;-0.78989;-0.66225;,
 -3.11189;0.02359;-0.10863;,
 0.00000;-5.32979;4.96570;,
 -3.42699;-5.32979;2.24793;,
 0.00000;-5.32979;-4.31336;,
 3.42699;-5.32979;2.24793;,
 4.84649;-5.32979;-4.31336;,
 3.42699;-5.32979;-10.87465;,
 0.00000;-5.32979;-12.47206;,
 -3.42699;-5.32979;-10.87465;,
 -4.84649;-5.32979;-4.31336;,
 0.00000;0.02359;-0.01444;,
 -3.42699;-4.16599;2.24793;,
 0.00000;-4.16599;4.96570;,
 3.42699;-4.16599;2.24793;,
 4.84649;-4.16599;-4.31336;,
 3.42699;-4.16599;-10.87465;,
 0.00000;-4.16599;-12.47206;,
 -3.42699;-4.16599;-10.87465;,
 -4.84649;-4.16599;-4.31336;;
 
 40;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,0,3,15;,
 3;16,17,18;,
 3;19,16,18;,
 3;20,19,18;,
 3;21,20,18;,
 3;22,21,18;,
 3;23,22,18;,
 3;24,23,18;,
 3;17,24,18;,
 3;3,2,25;,
 3;2,5,25;,
 3;5,7,25;,
 3;7,9,25;,
 3;9,11,25;,
 3;11,13,25;,
 3;13,15,25;,
 3;15,3,25;,
 4;26,27,1,0;,
 4;27,28,4,1;,
 4;28,29,6,4;,
 4;29,30,8,6;,
 4;30,31,10,8;,
 4;31,32,12,10;,
 4;32,33,14,12;,
 4;33,26,0,14;,
 4;17,16,27,26;,
 4;16,19,28,27;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,17,26,33;;
 
 MeshMaterialList {
  1;
  40;
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
  38;
  0.000000;-1.000000;0.000000;,
  -0.245987;0.947526;0.204171;,
  -0.000000;0.964465;0.264210;,
  0.245986;0.947526;0.204170;,
  0.336470;0.941627;0.011221;,
  0.180097;0.973269;-0.142520;,
  0.000000;0.985507;-0.169634;,
  -0.180098;0.973269;-0.142520;,
  -0.336472;0.941627;0.011222;,
  0.000000;1.000000;0.000000;,
  -0.699535;0.474359;0.534447;,
  -0.000000;0.856558;0.516051;,
  0.699535;0.474360;0.534447;,
  0.826605;0.562395;0.020887;,
  0.453441;0.832449;-0.318465;,
  0.000000;0.922738;-0.385428;,
  -0.453442;0.832448;-0.318465;,
  -0.826606;0.562394;0.020888;,
  -0.829612;0.033777;0.557318;,
  -0.585200;0.026203;0.810466;,
  0.829612;0.033776;0.557318;,
  0.988033;0.153961;0.009296;,
  0.731074;0.422673;-0.535611;,
  0.000000;0.900712;-0.434416;,
  -0.731074;0.422673;-0.535610;,
  -0.988033;0.153962;0.009296;,
  -0.547439;0.052335;0.835208;,
  0.585200;0.026203;0.810466;,
  0.547438;0.052334;0.835208;,
  -0.849012;0.000000;0.528374;,
  -0.621368;0.000000;0.783518;,
  0.621368;0.000000;0.783518;,
  0.849012;0.000000;0.528374;,
  1.000000;0.000000;0.000000;,
  0.781433;0.000000;-0.623989;,
  0.000000;0.000000;-1.000000;,
  -0.781433;0.000000;-0.623989;,
  -1.000000;0.000000;0.000000;;
  40;
  4;10,11,2,1;,
  4;11,12,3,2;,
  4;12,13,4,3;,
  4;13,14,5,4;,
  4;14,15,6,5;,
  4;15,16,7,6;,
  4;16,17,8,7;,
  4;17,10,1,8;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;1,2,9;,
  3;2,3,9;,
  3;3,4,9;,
  3;4,5,9;,
  3;5,6,9;,
  3;6,7,9;,
  3;7,8,9;,
  3;8,1,9;,
  4;18,19,26,10;,
  4;27,20,12,28;,
  4;20,21,13,12;,
  4;21,22,14,13;,
  4;22,23,15,14;,
  4;23,24,16,15;,
  4;24,25,17,16;,
  4;25,18,10,17;,
  4;29,30,19,18;,
  4;31,32,20,27;,
  4;32,33,21,20;,
  4;33,34,22,21;,
  4;34,35,35,22;,
  4;35,36,24,35;,
  4;36,37,25,24;,
  4;37,29,18,25;;
 }
 MeshTextureCoords {
  34;
  0.228443;0.656780;,
  0.197537;0.636455;,
  0.197537;0.653401;,
  0.221897;0.663265;,
  0.166632;0.656780;,
  0.173178;0.663265;,
  0.153831;0.705848;,
  0.163088;0.687078;,
  0.166632;0.754916;,
  0.173178;0.710891;,
  0.197537;0.775241;,
  0.197537;0.720755;,
  0.228443;0.754916;,
  0.221897;0.710891;,
  0.241244;0.705848;,
  0.231987;0.687078;,
  0.197537;0.629220;,
  0.235475;0.660208;,
  0.197537;0.735021;,
  0.159599;0.660208;,
  0.143885;0.735021;,
  0.159599;0.809834;,
  0.197537;0.840823;,
  0.235475;0.809834;,
  0.251190;0.735021;,
  0.197537;0.686004;,
  0.235475;0.660208;,
  0.197537;0.629220;,
  0.159599;0.660208;,
  0.143885;0.735021;,
  0.159599;0.809834;,
  0.197537;0.840823;,
  0.235475;0.809834;,
  0.251190;0.735021;;
 }
}
