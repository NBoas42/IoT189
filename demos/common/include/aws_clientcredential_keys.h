#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

#include <stdint.h>

/*
 * PEM-encoded client certificate.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWTCCAkGgAwIBAgIUR/QVGTeycBoBJF6NxVcN3nLT8HAwDQYJKoZIhvcNAQEL\n"\
"BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n"\
"SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTE5MDMxNDA0NTIz\n"\
"MFoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n"\
"ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMGxiyP307dT71alVyG/\n"\
"mYlcSWwT3M6xGZ92Y23hoNCJpPFadXB6fFqSV1ANApVLr71F5EMiRsR3vUqVLOTL\n"\
"Ft8uFIlizakS67qW+S6W7ih2upzR5GRKun99/65LIEvz1K7AXhIy1wik02Npbo9I\n"\
"aOFdfR6Iy8LQbBsrk1NUG7NttPItlwnWn+qZo3UoZhurCzR4z5Ors7rkodP9DR1D\n"\
"7y5xWV7aef1tghio0FCEaHw/zbO2+EF8Jpj7ajwa0MnFWUJS0bd2EvjIWSFUbOMr\n"\
"HIWbPiCDwX9x1XvMq87wJ/zzGtYqMblNF8ciiSNnmvdJ9HFomSGvbVA9annZdUQy\n"\
"MlcCAwEAAaNgMF4wHwYDVR0jBBgwFoAU7PVBsAR4RHEqmLJcuEYiwdsLzB0wHQYD\n"\
"VR0OBBYEFPocZLCCLwOZsSHJyHvAu1BMXuh2MAwGA1UdEwEB/wQCMAAwDgYDVR0P\n"\
"AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCFpbxginT/d+8SfjQ8aMyzjTcA\n"\
"MI2kJQtbNC24UC+YOSsUSYdlyVUJiff1lsF3IcklqIcf74tSZU7lGZG+mf+Lzb2z\n"\
"ufkxHMTt5L/zvBOaZbjb7GyaVSvGtEN9XWx2lritS4ne5t1Cd3hIMPV5YQZnOvFX\n"\
"N+0aFVXqAY+mla4AQARRfIIcxUHFOiki7qHvnYWV/4h/+JRUnlrPkZiEANoVdU4+\n"\
"GBn6AmJvfVTNVyARgDfHL5HPspukB/rzeEQ7k26jJ42VFzL+l4AtVed2fF09j0aw\n"\
"amyTqHjWi0tUILh7MSegcJLYMI8WlP1UiCYqDHQBbkU2nRY/u3y4fqHQGd5A\n"\
"-----END CERTIFICATE-----"

/*
 * PEM-encoded client private key.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEogIBAAKCAQEAwbGLI/fTt1PvVqVXIb+ZiVxJbBPczrEZn3ZjbeGg0Imk8Vp1\n"\
"cHp8WpJXUA0ClUuvvUXkQyJGxHe9SpUs5MsW3y4UiWLNqRLrupb5LpbuKHa6nNHk\n"\
"ZEq6f33/rksgS/PUrsBeEjLXCKTTY2luj0ho4V19HojLwtBsGyuTU1Qbs2208i2X\n"\
"Cdaf6pmjdShmG6sLNHjPk6uzuuSh0/0NHUPvLnFZXtp5/W2CGKjQUIRofD/Ns7b4\n"\
"QXwmmPtqPBrQycVZQlLRt3YS+MhZIVRs4yschZs+IIPBf3HVe8yrzvAn/PMa1iox\n"\
"uU0XxyKJI2ea90n0cWiZIa9tUD1qedl1RDIyVwIDAQABAoIBABVDAf0OxUTIh+tA\n"\
"9xGTUK1NXhnpDEH8Gs3wVvXG4LpDgcGkpmOUbnYavk7hPrlYt4/VTjs4VgBXDIZV\n"\
"Xbo3uOkCy+pQ2DaJBytSS0Qb+USj09RHDgUcVuCL2jcts/viZiRQpYLl5cjjHvk4\n"\
"p5Q+5JRoiMWDSqq16kgJPoDVKL1HSrJfTwCXuL+ALXNa9YtVdi63morgzUv+5vz5\n"\
"dixtXuteJHY+lcv2k93yrBjk8SgXoqp/lDrJkuw4aLuPxb9PGW+rov6aNJTw2ub8\n"\
"xQPMjrOL+EciR5o0HLY2j4yiR6DfUZlinK5X6Lokc/cNPMjlMDVaIsmT8+H0M1QC\n"\
"InU8NJECgYEA6vGpRXjD/CjGpLbSzuzBx93jxd9Xshj6vs7DwP/e0YluNqrCj5Gb\n"\
"djPj9pjceDR0y8iNUipb6RcoPMNF+krKNA94VXKE2NTIj1jMq+teeNgMyvVsZqdn\n"\
"LlyU57EnCIFQqvozoTSRx0DiODHrMKTBjzf4S/WCERat+JjBsyqod6UCgYEA0w14\n"\
"Pe1a5q9brftQFBOwM5pqSnPMxr8D5nDjfwFw9A4FofFDQcyHHCxGqegD0VsNT7P/\n"\
"NI97a32UFjNHqQ0Bzw4XYjZhfezctO+dUX6uuuA0tdDTybXRnNyg0nNEc7UtfLdN\n"\
"iEzFT71dxuPru09CibcvPymEffaDzGaOdDDJgUsCgYAToYWnTGPz2eRfNvd+WsIG\n"\
"VUAG9JZ7RyMMdnJc2gRgNb+Dydjf7iazRbqyjCs/0AJCVMuaJffwDgNKsHZUZ5Nl\n"\
"rjU7zonTJFRtxdm0M8J9DnBjNQaNvUcd1JaMlXzRdRysbKOLwLy9jWpZj7I7KkkS\n"\
"EncowabQjriSoRDuS44wEQKBgFGgXQf+e/DKk7fHgiIxty1OJJvlC6c2i4id0q71\n"\
"XL1XiwAmMrAJLZxM14uxK4DWKWDRKfwnHkHlkNfBP473c+Kj/ZFDnRM5/+aO4hZ5\n"\
"25R1UI2dVbwm8QotHpomcKwbv5sDvh3gK1P61oEs96g7MG3ZBpH0OcUKCdGNPL1d\n"\
"fSHfAoGAWJJ9HN0VkXF9X+BK/g2dazbYfcHXZCCblPqi2vowbE+rW3FoToxEPAqX\n"\
"aQ+jPjsfD5rscUNDMev9VL6nfKf1qHYJvZ882VGx/5he1iSGnTfXcIpCxNz3qniH\n"\
"6ydMBrErb/jhLGIRshhG5sdqzlX3V2QVaPF598MxjiStfIqIDAM=\n"\
"-----END RSA PRIVATE KEY-----"

/*
 * PEM-encoded Just-in-Time Registration (JITR) certificate (optional).
 *
 * If used, must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  NULL

/* The constants above are set to const char * pointers defined in aws_dev_mode_key_provisioning.c,
 * and externed here for use in C files.  NOTE!  THIS IS DONE FOR CONVENIENCE
 * DURING AN EVALUATION PHASE AND IS NOT GOOD PRACTICE FOR PRODUCTION SYSTEMS
 * WHICH MUST STORE KEYS SECURELY. */
extern const char clientcredentialCLIENT_CERTIFICATE_PEM[];
extern const char* clientcredentialJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM;
extern const char clientcredentialCLIENT_PRIVATE_KEY_PEM[];
extern const uint32_t clientcredentialCLIENT_CERTIFICATE_LENGTH;
extern const uint32_t clientcredentialCLIENT_PRIVATE_KEY_LENGTH;

#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
