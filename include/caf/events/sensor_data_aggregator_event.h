/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef _AGGREGATOR_EVENT_H_
#define _AGGREGATOR_EVENT_H_

/**
 * @file
 * @defgroup caf_sensor_data_aggregator_event CAF Sensor Data Aggregator Event
 * @{
 * @brief CAF Sensor Data Aggregator Event.
 */

#include <event_manager.h>
#include <event_manager_profiler_tracer.h>
#include "sensor_event.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Sensor data aggregator event.
 */
struct sensor_data_aggregator_event {
	struct event_header header;
	const char *sensor_descr;
	uint8_t *buf;
	enum sensor_state sensor_state;
	uint8_t sample_cnt;
};

/** @brief Sensor data aggregator release buffer event.
 *
 *  It is expected that exactly one release event is sent for each buffer.
 */
struct sensor_data_aggregator_release_buffer_event {
	struct event_header header;
	uint8_t *buf;
	const char *sensor_descr;
};

/**
 * @}
 */

EVENT_TYPE_DECLARE(sensor_data_aggregator_event);
EVENT_TYPE_DECLARE(sensor_data_aggregator_release_buffer_event);

#ifdef __cplusplus
}
#endif

#endif /* _AGGREGATOR_EVENT_H_ */
