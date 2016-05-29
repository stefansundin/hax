importPackage(java.io);
importPackage(java.lang);
S = new BufferedReader( new InputStreamReader(System['in']) );
s = true;
s = S.readLine();
while (s != '42') {
  print(s);
  s = S.readLine();
}
