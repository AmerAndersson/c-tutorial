#include <errno.h>
#include <gps.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  struct timeval tv;
  struct gps_data_t gps_data;

  if ((gps_open("localhost", "2947", &gps_data)) == -1) {
    printf("code: %d, reason: %s\n", errno, gps_errstr(errno));
    return EXIT_FAILURE;
  }

  gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);

  while (1) {
    if (gps_waiting(&gps_data, 2000000)) {
      if (gps_read(&gps_data, NULL, 0) == -1) {
        printf("error occurred reading GPS data. code: %d, reason: %s\n", errno, gps_errstr(errno));
      } else {
        if ((gps_data.status == STATUS_FIX) &&
            (gps_data.fix.mode == MODE_2D || gps_data.fix.mode == MODE_3D) &&
            !isnan(gps_data.fix.latitude) && !isnan(gps_data.fix.longitude)) {
          printf("latitude: %f, longitude: %f, altitude: %f\n",
                 gps_data.fix.latitude, gps_data.fix.longitude, gps_data.fix.altitude);
        } else {
          printf("no GPS data available\n");
        }
      }
    }
    sleep(3);
  }

  gps_stream(&gps_data, WATCH_DISABLE, NULL);
  gps_close(&gps_data);

  return EXIT_SUCCESS;
}
