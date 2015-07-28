/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /mnt/hgfs/workspace/libuavcan/dsdl/uavcan/equipment/esc/1035.FOCStatus.uavcan
 */

#ifndef UAVCAN_EQUIPMENT_ESC_FOCSTATUS_HPP_INCLUDED
#define UAVCAN_EQUIPMENT_ESC_FOCSTATUS_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# FOC ESC detailed status.
#

float16[2] i_dq              # Ampere
float16 i_setpoint           # Ampere

float16[2] v_dq              # Volt
float16[2] hfi_dq            # Ampere

float16 vbus                 # Volt
float16 temperature          # Kelvin

uint8 angle                  # Normalized [0,1)
uint8 consistency            # Normalized

float16 rpm
float16 rpm_setpoint

uint5 esc_index
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.esc.FOCStatus
saturated float16[2] i_dq
saturated float16 i_setpoint
saturated float16[2] v_dq
saturated float16[2] hfi_dq
saturated float16 vbus
saturated float16 temperature
saturated uint8 angle
saturated uint8 consistency
saturated float16 rpm
saturated float16 rpm_setpoint
saturated uint5 esc_index
******************************************************************************/

#undef i_dq
#undef i_setpoint
#undef v_dq
#undef hfi_dq
#undef vbus
#undef temperature
#undef angle
#undef consistency
#undef rpm
#undef rpm_setpoint
#undef esc_index

namespace uavcan
{
namespace equipment
{
namespace esc
{

template <int _tmpl>
struct UAVCAN_EXPORT FOCStatus_
{
    typedef const FOCStatus_<_tmpl>& ParameterType;
    typedef FOCStatus_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::Array< ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeStatic, 2 > i_dq;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > i_setpoint;
        typedef ::uavcan::Array< ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeStatic, 2 > v_dq;
        typedef ::uavcan::Array< ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeStatic, 2 > hfi_dq;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > vbus;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > temperature;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > angle;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > consistency;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > rpm;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > rpm_setpoint;
        typedef ::uavcan::IntegerSpec< 5, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > esc_index;
    };

    enum
    {
        MinBitLen
            = FieldTypes::i_dq::MinBitLen
            + FieldTypes::i_setpoint::MinBitLen
            + FieldTypes::v_dq::MinBitLen
            + FieldTypes::hfi_dq::MinBitLen
            + FieldTypes::vbus::MinBitLen
            + FieldTypes::temperature::MinBitLen
            + FieldTypes::angle::MinBitLen
            + FieldTypes::consistency::MinBitLen
            + FieldTypes::rpm::MinBitLen
            + FieldTypes::rpm_setpoint::MinBitLen
            + FieldTypes::esc_index::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::i_dq::MaxBitLen
            + FieldTypes::i_setpoint::MaxBitLen
            + FieldTypes::v_dq::MaxBitLen
            + FieldTypes::hfi_dq::MaxBitLen
            + FieldTypes::vbus::MaxBitLen
            + FieldTypes::temperature::MaxBitLen
            + FieldTypes::angle::MaxBitLen
            + FieldTypes::consistency::MaxBitLen
            + FieldTypes::rpm::MaxBitLen
            + FieldTypes::rpm_setpoint::MaxBitLen
            + FieldTypes::esc_index::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::i_dq >::Type i_dq;
    typename ::uavcan::StorageType< typename FieldTypes::i_setpoint >::Type i_setpoint;
    typename ::uavcan::StorageType< typename FieldTypes::v_dq >::Type v_dq;
    typename ::uavcan::StorageType< typename FieldTypes::hfi_dq >::Type hfi_dq;
    typename ::uavcan::StorageType< typename FieldTypes::vbus >::Type vbus;
    typename ::uavcan::StorageType< typename FieldTypes::temperature >::Type temperature;
    typename ::uavcan::StorageType< typename FieldTypes::angle >::Type angle;
    typename ::uavcan::StorageType< typename FieldTypes::consistency >::Type consistency;
    typename ::uavcan::StorageType< typename FieldTypes::rpm >::Type rpm;
    typename ::uavcan::StorageType< typename FieldTypes::rpm_setpoint >::Type rpm_setpoint;
    typename ::uavcan::StorageType< typename FieldTypes::esc_index >::Type esc_index;

    FOCStatus_()
        : i_dq()
        , i_setpoint()
        , v_dq()
        , hfi_dq()
        , vbus()
        , temperature()
        , angle()
        , consistency()
        , rpm()
        , rpm_setpoint()
        , esc_index()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<197 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 1035 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.equipment.esc.FOCStatus";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool FOCStatus_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        i_dq == rhs.i_dq &&
        i_setpoint == rhs.i_setpoint &&
        v_dq == rhs.v_dq &&
        hfi_dq == rhs.hfi_dq &&
        vbus == rhs.vbus &&
        temperature == rhs.temperature &&
        angle == rhs.angle &&
        consistency == rhs.consistency &&
        rpm == rhs.rpm &&
        rpm_setpoint == rhs.rpm_setpoint &&
        esc_index == rhs.esc_index;
}

template <int _tmpl>
bool FOCStatus_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(i_dq, rhs.i_dq) &&
        ::uavcan::areClose(i_setpoint, rhs.i_setpoint) &&
        ::uavcan::areClose(v_dq, rhs.v_dq) &&
        ::uavcan::areClose(hfi_dq, rhs.hfi_dq) &&
        ::uavcan::areClose(vbus, rhs.vbus) &&
        ::uavcan::areClose(temperature, rhs.temperature) &&
        ::uavcan::areClose(angle, rhs.angle) &&
        ::uavcan::areClose(consistency, rhs.consistency) &&
        ::uavcan::areClose(rpm, rhs.rpm) &&
        ::uavcan::areClose(rpm_setpoint, rhs.rpm_setpoint) &&
        ::uavcan::areClose(esc_index, rhs.esc_index);
}

template <int _tmpl>
int FOCStatus_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::i_dq::encode(self.i_dq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::i_setpoint::encode(self.i_setpoint, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::v_dq::encode(self.v_dq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::hfi_dq::encode(self.hfi_dq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::vbus::encode(self.vbus, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::temperature::encode(self.temperature, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::angle::encode(self.angle, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::consistency::encode(self.consistency, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::rpm::encode(self.rpm, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::rpm_setpoint::encode(self.rpm_setpoint, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::esc_index::encode(self.esc_index, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int FOCStatus_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::i_dq::decode(self.i_dq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::i_setpoint::decode(self.i_setpoint, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::v_dq::decode(self.v_dq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::hfi_dq::decode(self.hfi_dq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::vbus::decode(self.vbus, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::temperature::decode(self.temperature, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::angle::decode(self.angle, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::consistency::decode(self.consistency, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::rpm::decode(self.rpm, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::rpm_setpoint::decode(self.rpm_setpoint, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::esc_index::decode(self.esc_index, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature FOCStatus_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0xD28D6D017A39A083ULL);

    FieldTypes::i_dq::extendDataTypeSignature(signature);
    FieldTypes::i_setpoint::extendDataTypeSignature(signature);
    FieldTypes::v_dq::extendDataTypeSignature(signature);
    FieldTypes::hfi_dq::extendDataTypeSignature(signature);
    FieldTypes::vbus::extendDataTypeSignature(signature);
    FieldTypes::temperature::extendDataTypeSignature(signature);
    FieldTypes::angle::extendDataTypeSignature(signature);
    FieldTypes::consistency::extendDataTypeSignature(signature);
    FieldTypes::rpm::extendDataTypeSignature(signature);
    FieldTypes::rpm_setpoint::extendDataTypeSignature(signature);
    FieldTypes::esc_index::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef FOCStatus_<0> FOCStatus;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::equipment::esc::FOCStatus > _uavcan_gdtr_registrator_FOCStatus;

}

} // Namespace esc
} // Namespace equipment
} // Namespace uavcan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::equipment::esc::FOCStatus >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::equipment::esc::FOCStatus::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::equipment::esc::FOCStatus >::stream(Stream& s, ::uavcan::equipment::esc::FOCStatus::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "i_dq: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::i_dq >::stream(s, obj.i_dq, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "i_setpoint: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::i_setpoint >::stream(s, obj.i_setpoint, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "v_dq: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::v_dq >::stream(s, obj.v_dq, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "hfi_dq: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::hfi_dq >::stream(s, obj.hfi_dq, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "vbus: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::vbus >::stream(s, obj.vbus, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "temperature: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::temperature >::stream(s, obj.temperature, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "angle: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::angle >::stream(s, obj.angle, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "consistency: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::consistency >::stream(s, obj.consistency, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "rpm: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::rpm >::stream(s, obj.rpm, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "rpm_setpoint: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::rpm_setpoint >::stream(s, obj.rpm_setpoint, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "esc_index: ";
    YamlStreamer< ::uavcan::equipment::esc::FOCStatus::FieldTypes::esc_index >::stream(s, obj.esc_index, level + 1);
}

}

namespace uavcan
{
namespace equipment
{
namespace esc
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::equipment::esc::FOCStatus::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::equipment::esc::FOCStatus >::stream(s, obj, 0);
    return s;
}

} // Namespace esc
} // Namespace equipment
} // Namespace uavcan

#endif // UAVCAN_EQUIPMENT_ESC_FOCSTATUS_HPP_INCLUDED