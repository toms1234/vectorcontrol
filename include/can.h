/*
Copyright (c) 2014 - 2015 by Thiemar Pty Ltd

This file is part of vectorcontrol.

vectorcontrol is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

vectorcontrol is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
vectorcontrol. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <cstring>
#include "esc_assert.h"
#include "configuration.h"
#include "float16.h"


/* Debug (non-standard) message types */
enum can_nonstandard_message_id_t {
    CAN_STATUS_CONTROLLER = 0x730,
    CAN_STATUS_MEASUREMENT = 0x731,
    CAN_STATUS_CONFIG = 0x732,
    CAN_COMMAND_SETPOINT = 0x740,
    CAN_COMMAND_CONFIG = 0x741,
    CAN_COMMAND_RESTART = 0x742
};

struct can_status_controller_t {
    uint8_t node_id;
    float16_t id, iq;
    float16_t iq_setpoint;
} __attribute__ ((packed));

struct can_status_measurement_t {
    uint8_t node_id;
    int8_t temperature;
    int16_t rpm_setpoint;
    int16_t rpm;
    float16_t vbus;
} __attribute__ ((packed));

struct can_status_config_t {
    uint8_t node_id;
    uint8_t param_index;
    float param_value;
} __attribute__ ((packed));

struct can_command_setpoint_t {
    uint8_t node_id;
    uint8_t controller_mode;
    int16_t torque_setpoint;
    int16_t rpm_setpoint;
} __attribute__ ((packed));

struct can_command_config_t {
    uint8_t node_id;
    uint8_t param_index;
    uint8_t set;
    uint8_t save;
    float param_value;
} __attribute__ ((packed));

struct can_command_restart_t {
    uint8_t node_id;
    uint32_t magic;
} __attribute__ ((packed));

#define CAN_COMMAND_RESTART_MAGIC 1860004564u


/* UAVCAN message types */
enum uavcan_data_type_id_t {
    UAVCAN_RAWCOMMAND = 260,
    UAVCAN_RPMCOMMAND = 261,
    UAVCAN_ESCSTATUS = 601,
    UAVCAN_NODESTATUS = 550,
    UAVCAN_GETNODEINFO = 551,
    UAVCAN_RESTARTNODE = 560,
    UAVCAN_SAVEERASE = 598,
    UAVCAN_GETSET = 599,
    UAVCAN_PENDING = 0xFFFF
};

enum uavcan_transfer_type_t {
    UAVCAN_TRANSFER_SERVICE_RESPONSE = 0,
    UAVCAN_TRANSFER_SERVICE_REQUEST = 1,
    UAVCAN_TRANSFER_MESSAGE_BROADCAST = 2,
    UAVCAN_TRANSFER_MESSAGE_UNICAST = 3
};

enum uavcan_nodestatus_t {
    UAVCAN_NODESTATUS_OK = 0,
    UAVCAN_NODESTATUS_INITIALIZING = 1,
    UAVCAN_NODESTATUS_WARNING = 2,
    UAVCAN_NODESTATUS_CRITICAL = 3,
    UAVCAN_NODESTATUS_OFFLINE = 15
};

enum uavcan_saveerase_opcode_t {
    UAVCAN_SAVEERASE_OPCODE_SAVE = 0,
    UAVCAN_SAVEERASE_OPCODE_ERASE = 1
};


#define UAVCAN_RAWCOMMAND_SIGNATURE 0x217F5C87D7EC951Dull
#define UAVCAN_RPMCOMMAND_SIGNATURE 0xCE0F9F621CF7E70Bull
#define UAVCAN_ESCSTATUS_SIGNATURE 0xA9AF28AEA2FBB254ull
#define UAVCAN_NODESTATUS_SIGNATURE 0x72CF41D281C6F8D9ull
#define UAVCAN_GETNODEINFO_SIGNATURE 0x255D867097723D74ull
#define UAVCAN_RESTARTNODE_SIGNATURE 0xBCF56CB8AF9E1B10ull
#define UAVCAN_SAVEERASE_SIGNATURE 0x3EF0C62570A5811Eull
#define UAVCAN_GETSET_SIGNATURE 0xD316D89B5B15F483ull


#define UAVCAN_NODESTATUS_INTERVAL_MS 750u
#define UAVCAN_TRANSFER_TIMEOUT_INTERVAL_MS 100u


struct uavcan_esc_state_t {
    float vbus_v;
    float ibus_a;
    float temperature_degc;
    float speed_rpm;
    float power_pct;
};


#define CAN_STANDARD_ID_MASK 0x7FFu
#define CAN_EXTENDED_ID_MASK 0x1FFFFFFFu


class CANMessage {
protected:
    uint32_t id_;
    uint8_t data_[8];
    size_t data_length_;

public:
    CANMessage():
        id_(0),
        data_ {0, 0, 0, 0, 0, 0, 0, 0},
        data_length_(0)
    {}

    bool has_extended_id() const {
        return id_ & ~CAN_STANDARD_ID_MASK;
    }

    uint32_t get_id() const {
        return id_ & CAN_EXTENDED_ID_MASK;
    }

    void set_id(uint32_t id) {
        id_ = id;
    }

    size_t get_data(void *data) const {
        memcpy(data, data_, data_length_);
        return data_length_;
    }

    void set_data(size_t length, const void *data) {
        data_length_ = length;
        memcpy(data_, data, data_length_);
    }

    size_t get_length() const {
        return data_length_;
    }

    void set_length(size_t length) {
        data_length_ = length;
    }

    const uint8_t& operator[](int i) const {
        esc_assert(0 <= i && (size_t)i < data_length_);
        return data_[i];
    }

    uint8_t& operator[](int i) {
        esc_assert(0 <= i && (size_t)i < data_length_);
        return data_[i];
    }
};


#define UAVCAN_TRANSFER_ID_OFFSET 0u
#define UAVCAN_TRANSFER_ID_MASK 0x7u
#define UAVCAN_LAST_FRAME_OFFSET 3u
#define UAVCAN_LAST_FRAME_MASK 0x1u
#define UAVCAN_FRAME_INDEX_OFFSET 4u
#define UAVCAN_FRAME_INDEX_MASK 0x3Fu
#define UAVCAN_SOURCE_NODE_ID_OFFSET 10u
#define UAVCAN_SOURCE_NODE_ID_MASK 0x7Fu
#define UAVCAN_TRANSFER_TYPE_OFFSET 17u
#define UAVCAN_TRANSFER_TYPE_MASK 0x3u
#define UAVCAN_DATA_TYPE_ID_OFFSET 19u
#define UAVCAN_DATA_TYPE_ID_MASK 0x3FFu


class UAVCANMessage : public CANMessage {
public:
    UAVCANMessage(): CANMessage() {}
    UAVCANMessage(const CANMessage& m): CANMessage(m) {}

    /*
    Destination node ID getter/setter -- this is the first byte of the data
    field for unicast transfers. If the message is a broadcast, return 255.
    */
    uint8_t get_dest_node_id() const {
        if (get_transfer_type() == UAVCAN_TRANSFER_MESSAGE_BROADCAST) {
            return 0xFFu;
        } else {
            return (*this)[0];
        }
    }

    void set_dest_node_id(uint8_t node_id) {
        (*this)[0] = node_id;
    }

    /* Getters for data packed into the CAN ID field */
    uint8_t get_transfer_id() const {
        return (uint8_t)((get_id() >> UAVCAN_TRANSFER_ID_OFFSET) &
                         UAVCAN_TRANSFER_ID_MASK);
    }

    bool get_last_frame() const {
        return (bool)((get_id() >> UAVCAN_LAST_FRAME_OFFSET) &
                      UAVCAN_LAST_FRAME_MASK);
    }

    uint8_t get_frame_index() const {
        return (uint8_t)((get_id() >> UAVCAN_FRAME_INDEX_OFFSET) &
                         UAVCAN_FRAME_INDEX_MASK);
    }

    uint8_t get_source_node_id() const {
        return (uint8_t)((get_id() >> UAVCAN_SOURCE_NODE_ID_OFFSET) &
                         UAVCAN_SOURCE_NODE_ID_MASK);
    }

    uint8_t get_transfer_type() const {
        return (uint8_t)((get_id() >> UAVCAN_TRANSFER_TYPE_OFFSET) &
                         UAVCAN_TRANSFER_TYPE_MASK);
    }

    uint16_t get_data_type_id() const {
        return (uint16_t)((get_id() >> UAVCAN_DATA_TYPE_ID_OFFSET) &
                          UAVCAN_DATA_TYPE_ID_MASK);
    }

    /* Setters for data packed into the CAN ID field */
    void set_transfer_id(uint8_t transfer_id) {
        esc_assert((transfer_id & UAVCAN_TRANSFER_ID_MASK) == transfer_id);
        id_ &= ~(UAVCAN_TRANSFER_ID_MASK << UAVCAN_TRANSFER_ID_OFFSET);
        id_ |= transfer_id << UAVCAN_TRANSFER_ID_OFFSET;
    }

    void set_last_frame(bool last_frame) {
        esc_assert((last_frame & UAVCAN_LAST_FRAME_MASK) == last_frame);
        id_ &= ~(UAVCAN_LAST_FRAME_MASK << UAVCAN_LAST_FRAME_OFFSET);
        id_ |= (uint8_t)last_frame << UAVCAN_LAST_FRAME_OFFSET;
    }

    void set_frame_index(uint8_t frame_index) {
        esc_assert((frame_index & UAVCAN_FRAME_INDEX_MASK) == frame_index);
        id_ &= ~(UAVCAN_FRAME_INDEX_MASK << UAVCAN_FRAME_INDEX_OFFSET);
        id_ |= frame_index << UAVCAN_FRAME_INDEX_OFFSET;
    }

    void set_source_node_id(uint8_t source_node_id) {
        esc_assert((source_node_id & UAVCAN_SOURCE_NODE_ID_MASK) ==
                   source_node_id);
        id_ &= ~(UAVCAN_SOURCE_NODE_ID_MASK << UAVCAN_SOURCE_NODE_ID_OFFSET);
        id_ |= source_node_id << UAVCAN_SOURCE_NODE_ID_OFFSET;
    }

    void set_transfer_type(uint8_t transfer_type) {
        esc_assert((transfer_type & UAVCAN_TRANSFER_TYPE_MASK) == transfer_type);
        id_ &= ~(UAVCAN_TRANSFER_TYPE_MASK << UAVCAN_TRANSFER_TYPE_OFFSET);
        id_ |= transfer_type << UAVCAN_TRANSFER_TYPE_OFFSET;
    }

    void set_data_type_id(uint16_t data_type_id) {
        esc_assert((data_type_id & UAVCAN_DATA_TYPE_ID_MASK) == data_type_id);
        id_ &= ~(UAVCAN_DATA_TYPE_ID_MASK << UAVCAN_DATA_TYPE_ID_OFFSET);
        id_ |= data_type_id << UAVCAN_DATA_TYPE_ID_OFFSET;
    }
};


typedef bool (*uavcan_flash_save_callback_t)(void);
typedef bool (*uavcan_restart_request_callback_t)(void);
typedef bool (*uavcan_esc_command_callback_t)(enum uavcan_data_type_id_t, float);


class UAVCANServer {
    /* Flags for communicating between interrupt contexts */
    volatile uint8_t config_local_node_id_;
    volatile bool received_partial_frame_;
    volatile bool tx_transfer_done_;
    volatile bool rx_transfer_reset_;

    volatile uint16_t config_esc_status_interval_;
    volatile uint16_t config_esc_index_;

    /*
    May only be accessed from process_rx (receive interrupt context)
    */
    UAVCANMessage rx_transfer_;
    uint8_t rx_transfer_bytes_[64];
    size_t rx_transfer_length_;
    size_t rx_transfer_frame_index_;
    Configuration *configuration_;

    /*
    May be accessed from process_rx (receive interrupt context) or
    tick/process_tx (timer interrupt context)
    */
    volatile uint8_t tx_transfer_bytes_[64];
    volatile size_t tx_transfer_length_;
    volatile size_t tx_transfer_index_;
    volatile size_t tx_transfer_frame_index_;
    volatile uint8_t tx_transfer_dest_node_id_;
    volatile uint8_t tx_transfer_transfer_type_transfer_id_;
    volatile uint16_t tx_transfer_data_type_id_;

    /*
    May only be accessed from tick/process_tx (timer interrupt context)
    */
    uint8_t status_transfer_bytes_[16];
    size_t status_transfer_length_;
    size_t status_transfer_index_;
    size_t status_transfer_frame_index_;

    uint32_t uptime_ms_;
    uint32_t last_node_status_sent_time_ms_;
    uint32_t last_esc_status_sent_time_ms_;
    uint32_t last_esc_command_received_time_ms_;
    uint32_t last_partial_frame_received_time_ms_;

    /* 0 = node status, 1 = ESC status */
    uint8_t broadcast_transfer_ids_[4];

    /*
    RX callbacks -- will be called from process_rx (receive interrupt context)
    */
    uavcan_flash_save_callback_t flash_save_request_cb_;
    uavcan_restart_request_callback_t restart_request_cb_;
    uavcan_esc_command_callback_t esc_command_cb_;

    /* May be called from any context */
    uint16_t compute_crc(
        uint64_t data_type_signature,
        const volatile uint8_t* payload,
        size_t length
    );

    /* May only be called from process_rx (receive interrupt context) */
    void process_transfer();

    bool parse_saveerase_request(enum uavcan_saveerase_opcode_t& out_opcode);
    void serialize_saveerase_reply(bool ok);

    bool parse_getset_request(
        float& out_value,
        uint8_t& out_param_index,
        char *out_param_name
    );
    void serialize_getset_reply(const struct param_t& in_param);

    bool parse_restartnode_request();
    void serialize_restartnode_reply(bool ok);

    float get_esccommand_value();

    void reload_uavcan_config() {
        config_local_node_id_ = (uint8_t)
            configuration_->get_param_value_by_index(PARAM_UAVCAN_NODE_ID);
        config_esc_status_interval_ = (uint16_t)
            (configuration_->get_param_value_by_index(PARAM_UAVCAN_ESCSTATUS_INTERVAL) * 1000.0f);
        config_esc_index_ = (uint16_t)
            configuration_->get_param_value_by_index(PARAM_UAVCAN_ESC_INDEX);
    }

    /* May only be called from tick/process_tx (timer interrupt context) */
    void serialize_node_status(
        UAVCANMessage& out_message,
        uint8_t transfer_id,
        uint32_t uptime_s,
        enum uavcan_nodestatus_t status
    );

    void serialize_esc_status(
        const struct uavcan_esc_state_t& state
    );

public:
    UAVCANServer(Configuration& configuration):
        config_local_node_id_(0),
        received_partial_frame_(false),
        tx_transfer_done_(false),
        rx_transfer_reset_(false),
        config_esc_status_interval_(0),
        config_esc_index_(0),
        rx_transfer_(),
        rx_transfer_length_(0),
        rx_transfer_frame_index_(0),
        configuration_(&configuration),
        tx_transfer_length_(0),
        tx_transfer_index_(0),
        tx_transfer_frame_index_(0),
        tx_transfer_dest_node_id_(0),
        tx_transfer_transfer_type_transfer_id_(0),
        tx_transfer_data_type_id_(0),
        status_transfer_length_(0),
        status_transfer_index_(0),
        status_transfer_frame_index_(0),
        uptime_ms_(0),
        last_node_status_sent_time_ms_(0),
        last_esc_status_sent_time_ms_(0),
        last_esc_command_received_time_ms_(0),
        last_partial_frame_received_time_ms_(0),
        broadcast_transfer_ids_ {0, 0, 0, 0},
        flash_save_request_cb_(NULL),
        restart_request_cb_(NULL),
        esc_command_cb_(NULL)
    {
        reload_uavcan_config();
    }

    void tick(const struct uavcan_esc_state_t& state);

    void process_rx(const UAVCANMessage& in_message);
    bool process_tx(UAVCANMessage& out_message);

    void set_flash_save_callback(uavcan_flash_save_callback_t cb) {
        flash_save_request_cb_ = cb;
    }

    void set_restart_request_callback(uavcan_restart_request_callback_t cb) {
        restart_request_cb_ = cb;
    }

    void set_esc_command_callback(uavcan_esc_command_callback_t cb) {
        esc_command_cb_ = cb;
    }
};

