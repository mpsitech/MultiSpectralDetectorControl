

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DdsMsdc.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef DdsMsdcPlugin_1182984298_h
#define DdsMsdcPlugin_1182984298_h

#include "DdsMsdc.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define tinyintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define tinyintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define tinyintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define tinyintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define tinyintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern tinyint*
tinyintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern tinyint*
tinyintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tinyint*
tinyintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
tinyintPluginSupport_copy_data(
    tinyint *out,
    const tinyint *in);

NDDSUSERDllExport extern void 
tinyintPluginSupport_destroy_data_w_params(
    tinyint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
tinyintPluginSupport_destroy_data_ex(
    tinyint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tinyintPluginSupport_destroy_data(
    tinyint *sample);

NDDSUSERDllExport extern void 
tinyintPluginSupport_print_data(
    const tinyint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
tinyintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tinyint *out,
    const tinyint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
tinyintPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tinyint *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tinyintPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tinyint *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
tinyintPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
tinyintPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tinyint * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
tinyintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
tinyintPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tinyint *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tinyintPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tinyint * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
tinyintPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tinyint *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define utinyintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define utinyintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define utinyintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define utinyintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define utinyintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern utinyint*
utinyintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern utinyint*
utinyintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern utinyint*
utinyintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
utinyintPluginSupport_copy_data(
    utinyint *out,
    const utinyint *in);

NDDSUSERDllExport extern void 
utinyintPluginSupport_destroy_data_w_params(
    utinyint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
utinyintPluginSupport_destroy_data_ex(
    utinyint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
utinyintPluginSupport_destroy_data(
    utinyint *sample);

NDDSUSERDllExport extern void 
utinyintPluginSupport_print_data(
    const utinyint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
utinyintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    utinyint *out,
    const utinyint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
utinyintPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const utinyint *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
utinyintPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    utinyint *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
utinyintPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
utinyintPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const utinyint * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
utinyintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
utinyintPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const utinyint *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
utinyintPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    utinyint * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
utinyintPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    utinyint *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define smallintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define smallintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define smallintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define smallintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define smallintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern smallint*
smallintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern smallint*
smallintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern smallint*
smallintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
smallintPluginSupport_copy_data(
    smallint *out,
    const smallint *in);

NDDSUSERDllExport extern void 
smallintPluginSupport_destroy_data_w_params(
    smallint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
smallintPluginSupport_destroy_data_ex(
    smallint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
smallintPluginSupport_destroy_data(
    smallint *sample);

NDDSUSERDllExport extern void 
smallintPluginSupport_print_data(
    const smallint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
smallintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    smallint *out,
    const smallint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
smallintPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const smallint *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
smallintPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    smallint *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
smallintPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
smallintPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const smallint * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
smallintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
smallintPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const smallint *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
smallintPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    smallint * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
smallintPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    smallint *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define usmallintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define usmallintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define usmallintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define usmallintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define usmallintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern usmallint*
usmallintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern usmallint*
usmallintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern usmallint*
usmallintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
usmallintPluginSupport_copy_data(
    usmallint *out,
    const usmallint *in);

NDDSUSERDllExport extern void 
usmallintPluginSupport_destroy_data_w_params(
    usmallint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
usmallintPluginSupport_destroy_data_ex(
    usmallint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
usmallintPluginSupport_destroy_data(
    usmallint *sample);

NDDSUSERDllExport extern void 
usmallintPluginSupport_print_data(
    const usmallint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
usmallintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    usmallint *out,
    const usmallint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
usmallintPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const usmallint *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
usmallintPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    usmallint *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
usmallintPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
usmallintPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const usmallint * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
usmallintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
usmallintPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const usmallint *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
usmallintPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    usmallint * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
usmallintPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    usmallint *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define _cxx_intPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define _cxx_intPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define _cxx_intPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define _cxx_intPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define _cxx_intPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern _cxx_int*
_cxx_intPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern _cxx_int*
_cxx_intPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern _cxx_int*
_cxx_intPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
_cxx_intPluginSupport_copy_data(
    _cxx_int *out,
    const _cxx_int *in);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_destroy_data_w_params(
    _cxx_int *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_destroy_data_ex(
    _cxx_int *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_destroy_data(
    _cxx_int *sample);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_print_data(
    const _cxx_int *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
_cxx_intPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    _cxx_int *out,
    const _cxx_int *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
_cxx_intPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const _cxx_int *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
_cxx_intPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    _cxx_int *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
_cxx_intPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
_cxx_intPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const _cxx_int * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
_cxx_intPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
_cxx_intPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const _cxx_int *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
_cxx_intPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    _cxx_int * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
_cxx_intPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    _cxx_int *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define uintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define uintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define uintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define uintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define uintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern uint*
uintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern uint*
uintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern uint*
uintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
uintPluginSupport_copy_data(
    uint *out,
    const uint *in);

NDDSUSERDllExport extern void 
uintPluginSupport_destroy_data_w_params(
    uint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
uintPluginSupport_destroy_data_ex(
    uint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
uintPluginSupport_destroy_data(
    uint *sample);

NDDSUSERDllExport extern void 
uintPluginSupport_print_data(
    const uint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
uintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    uint *out,
    const uint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
uintPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const uint *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
uintPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    uint *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
uintPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
uintPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const uint * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
uintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
uintPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const uint *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
uintPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    uint * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
uintPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    uint *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define bigintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define bigintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define bigintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define bigintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define bigintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern bigint*
bigintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern bigint*
bigintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern bigint*
bigintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
bigintPluginSupport_copy_data(
    bigint *out,
    const bigint *in);

NDDSUSERDllExport extern void 
bigintPluginSupport_destroy_data_w_params(
    bigint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
bigintPluginSupport_destroy_data_ex(
    bigint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
bigintPluginSupport_destroy_data(
    bigint *sample);

NDDSUSERDllExport extern void 
bigintPluginSupport_print_data(
    const bigint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
bigintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    bigint *out,
    const bigint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
bigintPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const bigint *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
bigintPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    bigint *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
bigintPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
bigintPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const bigint * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
bigintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
bigintPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const bigint *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
bigintPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    bigint * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
bigintPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    bigint *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define ubigintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ubigintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ubigintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define ubigintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ubigintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ubigint*
ubigintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ubigint*
ubigintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ubigint*
ubigintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ubigintPluginSupport_copy_data(
    ubigint *out,
    const ubigint *in);

NDDSUSERDllExport extern void 
ubigintPluginSupport_destroy_data_w_params(
    ubigint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ubigintPluginSupport_destroy_data_ex(
    ubigint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ubigintPluginSupport_destroy_data(
    ubigint *sample);

NDDSUSERDllExport extern void 
ubigintPluginSupport_print_data(
    const ubigint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ubigintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ubigint *out,
    const ubigint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ubigintPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ubigint *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ubigintPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ubigint *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ubigintPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ubigintPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ubigint * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ubigintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ubigintPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ubigint *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ubigintPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ubigint * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ubigintPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ubigint *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define utinyintvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define utinyintvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define utinyintvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define utinyintvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define utinyintvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern utinyintvec*
utinyintvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern utinyintvec*
utinyintvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern utinyintvec*
utinyintvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
utinyintvecPluginSupport_copy_data(
    utinyintvec *out,
    const utinyintvec *in);

NDDSUSERDllExport extern void 
utinyintvecPluginSupport_destroy_data_w_params(
    utinyintvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
utinyintvecPluginSupport_destroy_data_ex(
    utinyintvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
utinyintvecPluginSupport_destroy_data(
    utinyintvec *sample);

NDDSUSERDllExport extern void 
utinyintvecPluginSupport_print_data(
    const utinyintvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
utinyintvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    utinyintvec *out,
    const utinyintvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
utinyintvecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const utinyintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
utinyintvecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    utinyintvec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
utinyintvecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
utinyintvecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
utinyintvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
utinyintvecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
utinyintvecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const utinyintvec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
utinyintvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
utinyintvecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
utinyintvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
utinyintvecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const utinyintvec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
utinyintvecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    utinyintvec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
utinyintvecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    utinyintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define usmallintvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define usmallintvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define usmallintvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define usmallintvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define usmallintvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern usmallintvec*
usmallintvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern usmallintvec*
usmallintvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern usmallintvec*
usmallintvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
usmallintvecPluginSupport_copy_data(
    usmallintvec *out,
    const usmallintvec *in);

NDDSUSERDllExport extern void 
usmallintvecPluginSupport_destroy_data_w_params(
    usmallintvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
usmallintvecPluginSupport_destroy_data_ex(
    usmallintvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
usmallintvecPluginSupport_destroy_data(
    usmallintvec *sample);

NDDSUSERDllExport extern void 
usmallintvecPluginSupport_print_data(
    const usmallintvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
usmallintvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    usmallintvec *out,
    const usmallintvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
usmallintvecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const usmallintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
usmallintvecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    usmallintvec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
usmallintvecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
usmallintvecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
usmallintvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
usmallintvecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
usmallintvecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const usmallintvec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
usmallintvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
usmallintvecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
usmallintvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
usmallintvecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const usmallintvec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
usmallintvecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    usmallintvec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
usmallintvecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    usmallintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define intvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define intvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define intvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define intvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define intvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern intvec*
intvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern intvec*
intvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern intvec*
intvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
intvecPluginSupport_copy_data(
    intvec *out,
    const intvec *in);

NDDSUSERDllExport extern void 
intvecPluginSupport_destroy_data_w_params(
    intvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
intvecPluginSupport_destroy_data_ex(
    intvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
intvecPluginSupport_destroy_data(
    intvec *sample);

NDDSUSERDllExport extern void 
intvecPluginSupport_print_data(
    const intvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
intvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    intvec *out,
    const intvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
intvecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const intvec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
intvecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    intvec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
intvecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
intvecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
intvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
intvecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
intvecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const intvec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
intvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
intvecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
intvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
intvecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const intvec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
intvecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    intvec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
intvecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    intvec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define uintvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define uintvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define uintvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define uintvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define uintvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern uintvec*
uintvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern uintvec*
uintvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern uintvec*
uintvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
uintvecPluginSupport_copy_data(
    uintvec *out,
    const uintvec *in);

NDDSUSERDllExport extern void 
uintvecPluginSupport_destroy_data_w_params(
    uintvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
uintvecPluginSupport_destroy_data_ex(
    uintvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
uintvecPluginSupport_destroy_data(
    uintvec *sample);

NDDSUSERDllExport extern void 
uintvecPluginSupport_print_data(
    const uintvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
uintvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    uintvec *out,
    const uintvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
uintvecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const uintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
uintvecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    uintvec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
uintvecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
uintvecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
uintvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
uintvecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
uintvecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const uintvec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
uintvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
uintvecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
uintvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
uintvecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const uintvec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
uintvecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    uintvec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
uintvecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    uintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define ubigintvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ubigintvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ubigintvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define ubigintvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ubigintvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ubigintvec*
ubigintvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ubigintvec*
ubigintvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ubigintvec*
ubigintvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ubigintvecPluginSupport_copy_data(
    ubigintvec *out,
    const ubigintvec *in);

NDDSUSERDllExport extern void 
ubigintvecPluginSupport_destroy_data_w_params(
    ubigintvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ubigintvecPluginSupport_destroy_data_ex(
    ubigintvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ubigintvecPluginSupport_destroy_data(
    ubigintvec *sample);

NDDSUSERDllExport extern void 
ubigintvecPluginSupport_print_data(
    const ubigintvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ubigintvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ubigintvec *out,
    const ubigintvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ubigintvecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ubigintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ubigintvecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ubigintvec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ubigintvecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ubigintvecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
ubigintvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ubigintvecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ubigintvecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ubigintvec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ubigintvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ubigintvecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ubigintvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ubigintvecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ubigintvec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ubigintvecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ubigintvec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ubigintvecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ubigintvec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define floatvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define floatvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define floatvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define floatvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define floatvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern floatvec*
floatvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern floatvec*
floatvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern floatvec*
floatvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
floatvecPluginSupport_copy_data(
    floatvec *out,
    const floatvec *in);

NDDSUSERDllExport extern void 
floatvecPluginSupport_destroy_data_w_params(
    floatvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
floatvecPluginSupport_destroy_data_ex(
    floatvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
floatvecPluginSupport_destroy_data(
    floatvec *sample);

NDDSUSERDllExport extern void 
floatvecPluginSupport_print_data(
    const floatvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
floatvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    floatvec *out,
    const floatvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
floatvecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const floatvec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
floatvecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    floatvec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
floatvecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
floatvecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
floatvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
floatvecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
floatvecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const floatvec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
floatvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
floatvecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
floatvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
floatvecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const floatvec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
floatvecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    floatvec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
floatvecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    floatvec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define doublevecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define doublevecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define doublevecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define doublevecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define doublevecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern doublevec*
doublevecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern doublevec*
doublevecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern doublevec*
doublevecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
doublevecPluginSupport_copy_data(
    doublevec *out,
    const doublevec *in);

NDDSUSERDllExport extern void 
doublevecPluginSupport_destroy_data_w_params(
    doublevec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
doublevecPluginSupport_destroy_data_ex(
    doublevec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
doublevecPluginSupport_destroy_data(
    doublevec *sample);

NDDSUSERDllExport extern void 
doublevecPluginSupport_print_data(
    const doublevec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
doublevecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    doublevec *out,
    const doublevec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
doublevecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const doublevec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
doublevecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    doublevec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
doublevecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
doublevecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
doublevecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
doublevecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
doublevecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const doublevec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
doublevecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
doublevecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
doublevecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
doublevecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const doublevec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
doublevecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    doublevec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
doublevecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    doublevec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define DdsFloatmatPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DdsFloatmatPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DdsFloatmatPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define DdsFloatmatPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DdsFloatmatPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DdsFloatmat*
DdsFloatmatPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DdsFloatmat*
DdsFloatmatPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DdsFloatmat*
DdsFloatmatPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPluginSupport_copy_data(
    DdsFloatmat *out,
    const DdsFloatmat *in);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_destroy_data_w_params(
    DdsFloatmat *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_destroy_data_ex(
    DdsFloatmat *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_destroy_data(
    DdsFloatmat *sample);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_print_data(
    const DdsFloatmat *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DdsFloatmatPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DdsFloatmatPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DdsFloatmatPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DdsFloatmatPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DdsFloatmatPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat *out,
    const DdsFloatmat *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DdsFloatmat *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsFloatmatPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DdsFloatmat *sample); 

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsFloatmatPlugin_deserialize_from_cdr_buffer(
    DdsFloatmat *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
DdsFloatmatPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DdsFloatmatPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DdsFloatmat * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DdsFloatmatPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DdsFloatmat *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsFloatmatPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DdsFloatmatPlugin_new(void);

NDDSUSERDllExport extern void
DdsFloatmatPlugin_delete(struct PRESTypePlugin *);

#define DdsDoublematPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DdsDoublematPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DdsDoublematPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define DdsDoublematPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DdsDoublematPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DdsDoublemat*
DdsDoublematPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DdsDoublemat*
DdsDoublematPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DdsDoublemat*
DdsDoublematPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DdsDoublematPluginSupport_copy_data(
    DdsDoublemat *out,
    const DdsDoublemat *in);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_destroy_data_w_params(
    DdsDoublemat *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_destroy_data_ex(
    DdsDoublemat *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_destroy_data(
    DdsDoublemat *sample);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_print_data(
    const DdsDoublemat *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DdsDoublematPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DdsDoublematPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DdsDoublematPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DdsDoublematPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DdsDoublematPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat *out,
    const DdsDoublemat *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DdsDoublemat *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsDoublematPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DdsDoublemat *sample); 

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsDoublematPlugin_deserialize_from_cdr_buffer(
    DdsDoublemat *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
DdsDoublematPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DdsDoublematPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DdsDoublemat * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DdsDoublematPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DdsDoublemat *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsDoublematPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DdsDoublematPlugin_new(void);

NDDSUSERDllExport extern void
DdsDoublematPlugin_delete(struct PRESTypePlugin *);

#define stringvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define stringvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define stringvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define stringvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define stringvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern stringvec*
stringvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern stringvec*
stringvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern stringvec*
stringvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
stringvecPluginSupport_copy_data(
    stringvec *out,
    const stringvec *in);

NDDSUSERDllExport extern void 
stringvecPluginSupport_destroy_data_w_params(
    stringvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
stringvecPluginSupport_destroy_data_ex(
    stringvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
stringvecPluginSupport_destroy_data(
    stringvec *sample);

NDDSUSERDllExport extern void 
stringvecPluginSupport_print_data(
    const stringvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
stringvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    stringvec *out,
    const stringvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
stringvecPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const stringvec *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
stringvecPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    stringvec *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
stringvecPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
stringvecPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const stringvec * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
stringvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
stringvecPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const stringvec *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
stringvecPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    stringvec * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
stringvecPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    stringvec *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

#define vecsrefPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define vecsrefPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define vecsrefPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define vecsrefPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define vecsrefPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern vecsref*
vecsrefPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern vecsref*
vecsrefPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern vecsref*
vecsrefPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
vecsrefPluginSupport_copy_data(
    vecsref *out,
    const vecsref *in);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_destroy_data_w_params(
    vecsref *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_destroy_data_ex(
    vecsref *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_destroy_data(
    vecsref *sample);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_print_data(
    const vecsref *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
vecsrefPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    vecsref *out,
    const vecsref *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
vecsrefPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const vecsref *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
vecsrefPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    vecsref *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
vecsrefPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
vecsrefPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const vecsref * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
vecsrefPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
vecsrefPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const vecsref *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
vecsrefPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    vecsref * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
vecsrefPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    vecsref *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

namespace DdsJobMsdcAcqAdxl {

    #define alphaBetaPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define alphaBetaPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define alphaBetaPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define alphaBetaPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define alphaBetaPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern alphaBeta*
    alphaBetaPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern alphaBeta*
    alphaBetaPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern alphaBeta*
    alphaBetaPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPluginSupport_copy_data(
        alphaBeta *out,
        const alphaBeta *in);

    NDDSUSERDllExport extern void 
    alphaBetaPluginSupport_destroy_data_w_params(
        alphaBeta *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    alphaBetaPluginSupport_destroy_data_ex(
        alphaBeta *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    alphaBetaPluginSupport_destroy_data(
        alphaBeta *sample);

    NDDSUSERDllExport extern void 
    alphaBetaPluginSupport_print_data(
        const alphaBeta *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    alphaBetaPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    alphaBetaPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    alphaBetaPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    alphaBetaPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    alphaBetaPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        alphaBeta *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        alphaBeta *out,
        const alphaBeta *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const alphaBeta *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        alphaBeta *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    alphaBetaPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const alphaBeta *sample); 

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        alphaBeta **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    alphaBetaPlugin_deserialize_from_cdr_buffer(
        alphaBeta *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    alphaBetaPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    alphaBetaPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    alphaBetaPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    alphaBetaPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    alphaBetaPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const alphaBeta * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    alphaBetaPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    alphaBetaPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    alphaBetaPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const alphaBeta *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        alphaBeta * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    alphaBetaPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        alphaBeta ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    alphaBetaPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        alphaBeta *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    alphaBetaPlugin_new(void);

    NDDSUSERDllExport extern void
    alphaBetaPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobMsdcAcqAdxl  */
namespace DdsJobMsdcAcqLwir {

    #define setOutput_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setOutput_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setOutput_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setOutput_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setOutput_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPluginSupport_copy_data(
        setOutput_req *out,
        const setOutput_req *in);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data_w_params(
        setOutput_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data_ex(
        setOutput_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data(
        setOutput_req *sample);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_print_data(
        const setOutput_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setOutput_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setOutput_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setOutput_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setOutput_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setOutput_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *out,
        const setOutput_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setOutput_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_deserialize_from_cdr_buffer(
        setOutput_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setOutput_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setOutput_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setOutput_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setOutput_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setOutput_reqPlugin_delete(struct PRESTypePlugin *);

    #define setOutput_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setOutput_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setOutput_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setOutput_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setOutput_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPluginSupport_copy_data(
        setOutput_reply *out,
        const setOutput_reply *in);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data_w_params(
        setOutput_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data_ex(
        setOutput_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data(
        setOutput_reply *sample);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_print_data(
        const setOutput_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setOutput_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setOutput_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setOutput_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setOutput_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setOutput_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *out,
        const setOutput_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setOutput_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_deserialize_from_cdr_buffer(
        setOutput_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setOutput_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setOutput_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setOutput_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setOutput_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setOutput_replyPlugin_delete(struct PRESTypePlugin *);

    #define start_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_reqPluginSupport_copy_data(
        start_req *out,
        const start_req *in);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_w_params(
        start_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_ex(
        start_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data(
        start_req *sample);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_print_data(
        const start_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *out,
        const start_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_deserialize_from_cdr_buffer(
        start_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    start_reqPlugin_delete(struct PRESTypePlugin *);

    #define start_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_replyPluginSupport_copy_data(
        start_reply *out,
        const start_reply *in);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_w_params(
        start_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_ex(
        start_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data(
        start_reply *sample);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_print_data(
        const start_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *out,
        const start_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_deserialize_from_cdr_buffer(
        start_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    start_replyPlugin_delete(struct PRESTypePlugin *);

    #define stop_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPluginSupport_copy_data(
        stop_req *out,
        const stop_req *in);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_w_params(
        stop_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_ex(
        stop_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data(
        stop_req *sample);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_print_data(
        const stop_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *out,
        const stop_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_deserialize_from_cdr_buffer(
        stop_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_reqPlugin_delete(struct PRESTypePlugin *);

    #define stop_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPluginSupport_copy_data(
        stop_reply *out,
        const stop_reply *in);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_w_params(
        stop_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_ex(
        stop_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data(
        stop_reply *sample);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_print_data(
        const stop_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *out,
        const stop_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_deserialize_from_cdr_buffer(
        stop_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_replyPlugin_delete(struct PRESTypePlugin *);

    #define seqnoTGray16Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define seqnoTGray16Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define seqnoTGray16Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define seqnoTGray16Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define seqnoTGray16Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern seqnoTGray16*
    seqnoTGray16PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern seqnoTGray16*
    seqnoTGray16PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern seqnoTGray16*
    seqnoTGray16PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16PluginSupport_copy_data(
        seqnoTGray16 *out,
        const seqnoTGray16 *in);

    NDDSUSERDllExport extern void 
    seqnoTGray16PluginSupport_destroy_data_w_params(
        seqnoTGray16 *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    seqnoTGray16PluginSupport_destroy_data_ex(
        seqnoTGray16 *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    seqnoTGray16PluginSupport_destroy_data(
        seqnoTGray16 *sample);

    NDDSUSERDllExport extern void 
    seqnoTGray16PluginSupport_print_data(
        const seqnoTGray16 *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    seqnoTGray16Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    seqnoTGray16Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    seqnoTGray16Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    seqnoTGray16Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    seqnoTGray16Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTGray16 *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTGray16 *out,
        const seqnoTGray16 *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16Plugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const seqnoTGray16 *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16Plugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTGray16 *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTGray16Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const seqnoTGray16 *sample); 

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16Plugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTGray16 **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTGray16Plugin_deserialize_from_cdr_buffer(
        seqnoTGray16 *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    seqnoTGray16Plugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    seqnoTGray16Plugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    seqnoTGray16Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    seqnoTGray16Plugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    seqnoTGray16Plugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const seqnoTGray16 * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    seqnoTGray16Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    seqnoTGray16Plugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    seqnoTGray16Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16Plugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const seqnoTGray16 *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16Plugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTGray16 * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTGray16Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTGray16 ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTGray16Plugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTGray16 *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    seqnoTGray16Plugin_new(void);

    NDDSUSERDllExport extern void
    seqnoTGray16Plugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobMsdcAcqLwir  */
namespace DdsJobMsdcAcqVisl {

    #define setFocus_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setFocus_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFocus_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setFocus_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFocus_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPluginSupport_copy_data(
        setFocus_req *out,
        const setFocus_req *in);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data_w_params(
        setFocus_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data_ex(
        setFocus_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data(
        setFocus_req *sample);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_print_data(
        const setFocus_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFocus_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFocus_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFocus_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFocus_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFocus_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *out,
        const setFocus_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFocus_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_deserialize_from_cdr_buffer(
        setFocus_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setFocus_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setFocus_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFocus_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFocus_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setFocus_reqPlugin_delete(struct PRESTypePlugin *);

    #define setFocus_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setFocus_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFocus_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setFocus_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFocus_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPluginSupport_copy_data(
        setFocus_reply *out,
        const setFocus_reply *in);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data_w_params(
        setFocus_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data_ex(
        setFocus_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data(
        setFocus_reply *sample);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_print_data(
        const setFocus_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFocus_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFocus_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFocus_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFocus_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFocus_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *out,
        const setFocus_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFocus_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_deserialize_from_cdr_buffer(
        setFocus_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setFocus_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setFocus_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFocus_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFocus_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setFocus_replyPlugin_delete(struct PRESTypePlugin *);

    #define setOutput_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setOutput_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setOutput_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setOutput_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setOutput_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPluginSupport_copy_data(
        setOutput_req *out,
        const setOutput_req *in);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data_w_params(
        setOutput_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data_ex(
        setOutput_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data(
        setOutput_req *sample);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_print_data(
        const setOutput_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setOutput_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setOutput_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setOutput_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setOutput_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setOutput_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *out,
        const setOutput_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setOutput_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_deserialize_from_cdr_buffer(
        setOutput_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setOutput_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setOutput_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setOutput_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setOutput_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setOutput_reqPlugin_delete(struct PRESTypePlugin *);

    #define setOutput_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setOutput_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setOutput_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setOutput_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setOutput_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPluginSupport_copy_data(
        setOutput_reply *out,
        const setOutput_reply *in);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data_w_params(
        setOutput_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data_ex(
        setOutput_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data(
        setOutput_reply *sample);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_print_data(
        const setOutput_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setOutput_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setOutput_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setOutput_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setOutput_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setOutput_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *out,
        const setOutput_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setOutput_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_deserialize_from_cdr_buffer(
        setOutput_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setOutput_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setOutput_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setOutput_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setOutput_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setOutput_replyPlugin_delete(struct PRESTypePlugin *);

    #define setTint_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setTint_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setTint_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setTint_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setTint_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setTint_req*
    setTint_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setTint_req*
    setTint_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setTint_req*
    setTint_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPluginSupport_copy_data(
        setTint_req *out,
        const setTint_req *in);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_destroy_data_w_params(
        setTint_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_destroy_data_ex(
        setTint_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_destroy_data(
        setTint_req *sample);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_print_data(
        const setTint_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setTint_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setTint_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setTint_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setTint_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setTint_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *out,
        const setTint_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setTint_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_deserialize_from_cdr_buffer(
        setTint_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setTint_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setTint_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setTint_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setTint_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setTint_reqPlugin_delete(struct PRESTypePlugin *);

    #define setTint_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setTint_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setTint_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setTint_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setTint_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setTint_reply*
    setTint_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setTint_reply*
    setTint_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setTint_reply*
    setTint_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPluginSupport_copy_data(
        setTint_reply *out,
        const setTint_reply *in);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_destroy_data_w_params(
        setTint_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_destroy_data_ex(
        setTint_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_destroy_data(
        setTint_reply *sample);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_print_data(
        const setTint_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setTint_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setTint_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setTint_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setTint_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setTint_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *out,
        const setTint_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setTint_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_deserialize_from_cdr_buffer(
        setTint_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setTint_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setTint_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setTint_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setTint_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setTint_replyPlugin_delete(struct PRESTypePlugin *);

    #define start_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_reqPluginSupport_copy_data(
        start_req *out,
        const start_req *in);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_w_params(
        start_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_ex(
        start_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data(
        start_req *sample);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_print_data(
        const start_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *out,
        const start_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_deserialize_from_cdr_buffer(
        start_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    start_reqPlugin_delete(struct PRESTypePlugin *);

    #define start_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_replyPluginSupport_copy_data(
        start_reply *out,
        const start_reply *in);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_w_params(
        start_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_ex(
        start_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data(
        start_reply *sample);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_print_data(
        const start_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *out,
        const start_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_deserialize_from_cdr_buffer(
        start_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    start_replyPlugin_delete(struct PRESTypePlugin *);

    #define stop_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPluginSupport_copy_data(
        stop_req *out,
        const stop_req *in);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_w_params(
        stop_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_ex(
        stop_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data(
        stop_req *sample);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_print_data(
        const stop_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *out,
        const stop_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_deserialize_from_cdr_buffer(
        stop_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_reqPlugin_delete(struct PRESTypePlugin *);

    #define stop_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPluginSupport_copy_data(
        stop_reply *out,
        const stop_reply *in);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_w_params(
        stop_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_ex(
        stop_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data(
        stop_reply *sample);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_print_data(
        const stop_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *out,
        const stop_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_deserialize_from_cdr_buffer(
        stop_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_replyPlugin_delete(struct PRESTypePlugin *);

    #define seqnoTRgbx8Gray8Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define seqnoTRgbx8Gray8Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define seqnoTRgbx8Gray8Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define seqnoTRgbx8Gray8Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define seqnoTRgbx8Gray8Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern seqnoTRgbx8Gray8*
    seqnoTRgbx8Gray8PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern seqnoTRgbx8Gray8*
    seqnoTRgbx8Gray8PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern seqnoTRgbx8Gray8*
    seqnoTRgbx8Gray8PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8PluginSupport_copy_data(
        seqnoTRgbx8Gray8 *out,
        const seqnoTRgbx8Gray8 *in);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_destroy_data_w_params(
        seqnoTRgbx8Gray8 *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_destroy_data_ex(
        seqnoTRgbx8Gray8 *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_destroy_data(
        seqnoTRgbx8Gray8 *sample);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_print_data(
        const seqnoTRgbx8Gray8 *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    seqnoTRgbx8Gray8Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    seqnoTRgbx8Gray8Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    seqnoTRgbx8Gray8Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *out,
        const seqnoTRgbx8Gray8 *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const seqnoTRgbx8Gray8 *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const seqnoTRgbx8Gray8 *sample); 

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_deserialize_from_cdr_buffer(
        seqnoTRgbx8Gray8 *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const seqnoTRgbx8Gray8 * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    seqnoTRgbx8Gray8Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const seqnoTRgbx8Gray8 *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    seqnoTRgbx8Gray8Plugin_new(void);

    NDDSUSERDllExport extern void
    seqnoTRgbx8Gray8Plugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobMsdcAcqVisl  */
namespace DdsJobMsdcAcqVisr {

    #define setFocus_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setFocus_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFocus_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setFocus_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFocus_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPluginSupport_copy_data(
        setFocus_req *out,
        const setFocus_req *in);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data_w_params(
        setFocus_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data_ex(
        setFocus_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data(
        setFocus_req *sample);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_print_data(
        const setFocus_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFocus_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFocus_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFocus_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFocus_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFocus_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *out,
        const setFocus_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFocus_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_deserialize_from_cdr_buffer(
        setFocus_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setFocus_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setFocus_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFocus_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFocus_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setFocus_reqPlugin_delete(struct PRESTypePlugin *);

    #define setFocus_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setFocus_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFocus_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setFocus_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFocus_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPluginSupport_copy_data(
        setFocus_reply *out,
        const setFocus_reply *in);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data_w_params(
        setFocus_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data_ex(
        setFocus_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data(
        setFocus_reply *sample);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_print_data(
        const setFocus_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFocus_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFocus_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFocus_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFocus_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFocus_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *out,
        const setFocus_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFocus_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_deserialize_from_cdr_buffer(
        setFocus_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setFocus_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setFocus_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFocus_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setFocus_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFocus_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setFocus_replyPlugin_delete(struct PRESTypePlugin *);

    #define setOutput_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setOutput_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setOutput_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setOutput_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setOutput_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setOutput_req*
    setOutput_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPluginSupport_copy_data(
        setOutput_req *out,
        const setOutput_req *in);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data_w_params(
        setOutput_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data_ex(
        setOutput_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_destroy_data(
        setOutput_req *sample);

    NDDSUSERDllExport extern void 
    setOutput_reqPluginSupport_print_data(
        const setOutput_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setOutput_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setOutput_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setOutput_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setOutput_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setOutput_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *out,
        const setOutput_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setOutput_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_deserialize_from_cdr_buffer(
        setOutput_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setOutput_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setOutput_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setOutput_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setOutput_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setOutput_reqPlugin_delete(struct PRESTypePlugin *);

    #define setOutput_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setOutput_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setOutput_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setOutput_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setOutput_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setOutput_reply*
    setOutput_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPluginSupport_copy_data(
        setOutput_reply *out,
        const setOutput_reply *in);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data_w_params(
        setOutput_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data_ex(
        setOutput_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_destroy_data(
        setOutput_reply *sample);

    NDDSUSERDllExport extern void 
    setOutput_replyPluginSupport_print_data(
        const setOutput_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setOutput_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setOutput_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setOutput_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setOutput_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setOutput_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *out,
        const setOutput_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setOutput_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_deserialize_from_cdr_buffer(
        setOutput_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setOutput_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setOutput_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setOutput_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setOutput_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setOutput_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setOutput_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setOutput_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setOutput_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setOutput_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setOutput_replyPlugin_delete(struct PRESTypePlugin *);

    #define setTint_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setTint_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setTint_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setTint_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setTint_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setTint_req*
    setTint_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setTint_req*
    setTint_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setTint_req*
    setTint_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPluginSupport_copy_data(
        setTint_req *out,
        const setTint_req *in);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_destroy_data_w_params(
        setTint_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_destroy_data_ex(
        setTint_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_destroy_data(
        setTint_req *sample);

    NDDSUSERDllExport extern void 
    setTint_reqPluginSupport_print_data(
        const setTint_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setTint_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setTint_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setTint_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setTint_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setTint_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *out,
        const setTint_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setTint_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_deserialize_from_cdr_buffer(
        setTint_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setTint_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setTint_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setTint_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setTint_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setTint_reqPlugin_delete(struct PRESTypePlugin *);

    #define setTint_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setTint_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setTint_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setTint_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setTint_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setTint_reply*
    setTint_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setTint_reply*
    setTint_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setTint_reply*
    setTint_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPluginSupport_copy_data(
        setTint_reply *out,
        const setTint_reply *in);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_destroy_data_w_params(
        setTint_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_destroy_data_ex(
        setTint_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_destroy_data(
        setTint_reply *sample);

    NDDSUSERDllExport extern void 
    setTint_replyPluginSupport_print_data(
        const setTint_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setTint_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setTint_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setTint_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setTint_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setTint_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *out,
        const setTint_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setTint_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_deserialize_from_cdr_buffer(
        setTint_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setTint_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setTint_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setTint_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTint_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setTint_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTint_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTint_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setTint_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setTint_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setTint_replyPlugin_delete(struct PRESTypePlugin *);

    #define start_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_reqPluginSupport_copy_data(
        start_req *out,
        const start_req *in);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_w_params(
        start_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_ex(
        start_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data(
        start_req *sample);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_print_data(
        const start_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *out,
        const start_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_deserialize_from_cdr_buffer(
        start_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    start_reqPlugin_delete(struct PRESTypePlugin *);

    #define start_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_replyPluginSupport_copy_data(
        start_reply *out,
        const start_reply *in);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_w_params(
        start_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_ex(
        start_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data(
        start_reply *sample);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_print_data(
        const start_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *out,
        const start_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_deserialize_from_cdr_buffer(
        start_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    start_replyPlugin_delete(struct PRESTypePlugin *);

    #define stop_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPluginSupport_copy_data(
        stop_req *out,
        const stop_req *in);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_w_params(
        stop_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_ex(
        stop_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data(
        stop_req *sample);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_print_data(
        const stop_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *out,
        const stop_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_deserialize_from_cdr_buffer(
        stop_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_reqPlugin_delete(struct PRESTypePlugin *);

    #define stop_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPluginSupport_copy_data(
        stop_reply *out,
        const stop_reply *in);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_w_params(
        stop_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_ex(
        stop_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data(
        stop_reply *sample);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_print_data(
        const stop_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *out,
        const stop_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_deserialize_from_cdr_buffer(
        stop_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_replyPlugin_delete(struct PRESTypePlugin *);

    #define seqnoTRgbx8Gray8Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define seqnoTRgbx8Gray8Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define seqnoTRgbx8Gray8Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define seqnoTRgbx8Gray8Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define seqnoTRgbx8Gray8Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern seqnoTRgbx8Gray8*
    seqnoTRgbx8Gray8PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern seqnoTRgbx8Gray8*
    seqnoTRgbx8Gray8PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern seqnoTRgbx8Gray8*
    seqnoTRgbx8Gray8PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8PluginSupport_copy_data(
        seqnoTRgbx8Gray8 *out,
        const seqnoTRgbx8Gray8 *in);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_destroy_data_w_params(
        seqnoTRgbx8Gray8 *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_destroy_data_ex(
        seqnoTRgbx8Gray8 *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_destroy_data(
        seqnoTRgbx8Gray8 *sample);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8PluginSupport_print_data(
        const seqnoTRgbx8Gray8 *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    seqnoTRgbx8Gray8Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    seqnoTRgbx8Gray8Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    seqnoTRgbx8Gray8Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    seqnoTRgbx8Gray8Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *out,
        const seqnoTRgbx8Gray8 *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const seqnoTRgbx8Gray8 *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const seqnoTRgbx8Gray8 *sample); 

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_deserialize_from_cdr_buffer(
        seqnoTRgbx8Gray8 *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    seqnoTRgbx8Gray8Plugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const seqnoTRgbx8Gray8 * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    seqnoTRgbx8Gray8Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    seqnoTRgbx8Gray8Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const seqnoTRgbx8Gray8 *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    seqnoTRgbx8Gray8Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    seqnoTRgbx8Gray8Plugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        seqnoTRgbx8Gray8 *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    seqnoTRgbx8Gray8Plugin_new(void);

    NDDSUSERDllExport extern void
    seqnoTRgbx8Gray8Plugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobMsdcAcqVisr  */
namespace DdsJobMsdcActAlign {

    #define setWave_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setWave_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setWave_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setWave_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setWave_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setWave_req*
    setWave_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setWave_req*
    setWave_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setWave_req*
    setWave_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPluginSupport_copy_data(
        setWave_req *out,
        const setWave_req *in);

    NDDSUSERDllExport extern void 
    setWave_reqPluginSupport_destroy_data_w_params(
        setWave_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setWave_reqPluginSupport_destroy_data_ex(
        setWave_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setWave_reqPluginSupport_destroy_data(
        setWave_req *sample);

    NDDSUSERDllExport extern void 
    setWave_reqPluginSupport_print_data(
        const setWave_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setWave_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setWave_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setWave_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setWave_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setWave_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_req *out,
        const setWave_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setWave_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setWave_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setWave_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setWave_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setWave_reqPlugin_deserialize_from_cdr_buffer(
        setWave_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setWave_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setWave_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setWave_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setWave_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setWave_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setWave_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setWave_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setWave_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setWave_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setWave_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setWave_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setWave_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setWave_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setWave_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setWave_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setWave_reqPlugin_delete(struct PRESTypePlugin *);

    #define setWave_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setWave_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setWave_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setWave_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setWave_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setWave_reply*
    setWave_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setWave_reply*
    setWave_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setWave_reply*
    setWave_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPluginSupport_copy_data(
        setWave_reply *out,
        const setWave_reply *in);

    NDDSUSERDllExport extern void 
    setWave_replyPluginSupport_destroy_data_w_params(
        setWave_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setWave_replyPluginSupport_destroy_data_ex(
        setWave_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setWave_replyPluginSupport_destroy_data(
        setWave_reply *sample);

    NDDSUSERDllExport extern void 
    setWave_replyPluginSupport_print_data(
        const setWave_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setWave_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setWave_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setWave_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setWave_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setWave_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_reply *out,
        const setWave_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setWave_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setWave_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setWave_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setWave_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setWave_replyPlugin_deserialize_from_cdr_buffer(
        setWave_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setWave_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setWave_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setWave_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setWave_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setWave_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setWave_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setWave_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setWave_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setWave_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setWave_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setWave_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setWave_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setWave_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setWave_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setWave_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setWave_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setWave_replyPlugin_delete(struct PRESTypePlugin *);

    #define start_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_req*
    start_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_reqPluginSupport_copy_data(
        start_req *out,
        const start_req *in);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_w_params(
        start_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data_ex(
        start_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_destroy_data(
        start_req *sample);

    NDDSUSERDllExport extern void 
    start_reqPluginSupport_print_data(
        const start_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *out,
        const start_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_deserialize_from_cdr_buffer(
        start_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    start_reqPlugin_delete(struct PRESTypePlugin *);

    #define start_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define start_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define start_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define start_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define start_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern start_reply*
    start_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    start_replyPluginSupport_copy_data(
        start_reply *out,
        const start_reply *in);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_w_params(
        start_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data_ex(
        start_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_destroy_data(
        start_reply *sample);

    NDDSUSERDllExport extern void 
    start_replyPluginSupport_print_data(
        const start_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    start_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    start_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    start_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    start_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *out,
        const start_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const start_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        start_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_deserialize_from_cdr_buffer(
        start_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    start_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const start_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    start_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    start_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const start_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        start_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    start_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    start_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        start_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    start_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    start_replyPlugin_delete(struct PRESTypePlugin *);

    #define stop_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPluginSupport_copy_data(
        stop_req *out,
        const stop_req *in);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_w_params(
        stop_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_ex(
        stop_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data(
        stop_req *sample);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_print_data(
        const stop_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *out,
        const stop_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_deserialize_from_cdr_buffer(
        stop_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_reqPlugin_delete(struct PRESTypePlugin *);

    #define stop_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define stop_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define stop_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPluginSupport_copy_data(
        stop_reply *out,
        const stop_reply *in);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_w_params(
        stop_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_ex(
        stop_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data(
        stop_reply *sample);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_print_data(
        const stop_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *out,
        const stop_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_deserialize_from_cdr_buffer(
        stop_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    stop_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const stop_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const stop_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_replyPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobMsdcActAlign  */
namespace DdsJobMsdcActLed {

    #define setFlood_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setFlood_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFlood_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setFlood_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFlood_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFlood_req*
    setFlood_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFlood_req*
    setFlood_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFlood_req*
    setFlood_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPluginSupport_copy_data(
        setFlood_req *out,
        const setFlood_req *in);

    NDDSUSERDllExport extern void 
    setFlood_reqPluginSupport_destroy_data_w_params(
        setFlood_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFlood_reqPluginSupport_destroy_data_ex(
        setFlood_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFlood_reqPluginSupport_destroy_data(
        setFlood_req *sample);

    NDDSUSERDllExport extern void 
    setFlood_reqPluginSupport_print_data(
        const setFlood_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFlood_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFlood_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFlood_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFlood_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFlood_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_req *out,
        const setFlood_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setFlood_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFlood_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFlood_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFlood_reqPlugin_deserialize_from_cdr_buffer(
        setFlood_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setFlood_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setFlood_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setFlood_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFlood_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setFlood_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setFlood_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFlood_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFlood_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFlood_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setFlood_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFlood_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFlood_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFlood_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setFlood_reqPlugin_delete(struct PRESTypePlugin *);

    #define setFlood_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setFlood_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFlood_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setFlood_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFlood_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFlood_reply*
    setFlood_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFlood_reply*
    setFlood_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFlood_reply*
    setFlood_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPluginSupport_copy_data(
        setFlood_reply *out,
        const setFlood_reply *in);

    NDDSUSERDllExport extern void 
    setFlood_replyPluginSupport_destroy_data_w_params(
        setFlood_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFlood_replyPluginSupport_destroy_data_ex(
        setFlood_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFlood_replyPluginSupport_destroy_data(
        setFlood_reply *sample);

    NDDSUSERDllExport extern void 
    setFlood_replyPluginSupport_print_data(
        const setFlood_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFlood_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFlood_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFlood_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFlood_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFlood_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_reply *out,
        const setFlood_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setFlood_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFlood_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFlood_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFlood_replyPlugin_deserialize_from_cdr_buffer(
        setFlood_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setFlood_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setFlood_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setFlood_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFlood_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setFlood_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setFlood_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFlood_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFlood_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFlood_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setFlood_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setFlood_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFlood_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setFlood_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFlood_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setFlood_replyPlugin_delete(struct PRESTypePlugin *);

    #define setSpot_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setSpot_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setSpot_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setSpot_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setSpot_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setSpot_req*
    setSpot_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setSpot_req*
    setSpot_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setSpot_req*
    setSpot_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPluginSupport_copy_data(
        setSpot_req *out,
        const setSpot_req *in);

    NDDSUSERDllExport extern void 
    setSpot_reqPluginSupport_destroy_data_w_params(
        setSpot_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setSpot_reqPluginSupport_destroy_data_ex(
        setSpot_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setSpot_reqPluginSupport_destroy_data(
        setSpot_req *sample);

    NDDSUSERDllExport extern void 
    setSpot_reqPluginSupport_print_data(
        const setSpot_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setSpot_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setSpot_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setSpot_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setSpot_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setSpot_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_req *out,
        const setSpot_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setSpot_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setSpot_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setSpot_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setSpot_reqPlugin_deserialize_from_cdr_buffer(
        setSpot_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setSpot_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setSpot_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setSpot_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setSpot_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setSpot_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setSpot_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setSpot_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setSpot_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setSpot_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setSpot_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setSpot_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setSpot_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setSpot_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setSpot_reqPlugin_delete(struct PRESTypePlugin *);

    #define setSpot_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setSpot_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setSpot_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setSpot_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setSpot_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setSpot_reply*
    setSpot_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setSpot_reply*
    setSpot_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setSpot_reply*
    setSpot_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPluginSupport_copy_data(
        setSpot_reply *out,
        const setSpot_reply *in);

    NDDSUSERDllExport extern void 
    setSpot_replyPluginSupport_destroy_data_w_params(
        setSpot_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setSpot_replyPluginSupport_destroy_data_ex(
        setSpot_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setSpot_replyPluginSupport_destroy_data(
        setSpot_reply *sample);

    NDDSUSERDllExport extern void 
    setSpot_replyPluginSupport_print_data(
        const setSpot_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setSpot_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setSpot_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setSpot_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setSpot_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setSpot_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_reply *out,
        const setSpot_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setSpot_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setSpot_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setSpot_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setSpot_replyPlugin_deserialize_from_cdr_buffer(
        setSpot_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setSpot_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setSpot_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setSpot_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setSpot_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setSpot_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setSpot_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setSpot_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setSpot_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setSpot_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setSpot_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setSpot_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setSpot_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setSpot_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setSpot_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setSpot_replyPlugin_delete(struct PRESTypePlugin *);

    #define floodSpotPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define floodSpotPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define floodSpotPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define floodSpotPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define floodSpotPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern floodSpot*
    floodSpotPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern floodSpot*
    floodSpotPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern floodSpot*
    floodSpotPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    floodSpotPluginSupport_copy_data(
        floodSpot *out,
        const floodSpot *in);

    NDDSUSERDllExport extern void 
    floodSpotPluginSupport_destroy_data_w_params(
        floodSpot *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    floodSpotPluginSupport_destroy_data_ex(
        floodSpot *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    floodSpotPluginSupport_destroy_data(
        floodSpot *sample);

    NDDSUSERDllExport extern void 
    floodSpotPluginSupport_print_data(
        const floodSpot *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    floodSpotPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    floodSpotPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    floodSpotPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    floodSpotPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    floodSpotPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        floodSpot *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    floodSpotPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        floodSpot *out,
        const floodSpot *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    floodSpotPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const floodSpot *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    floodSpotPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        floodSpot *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    floodSpotPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const floodSpot *sample); 

    NDDSUSERDllExport extern RTIBool 
    floodSpotPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        floodSpot **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    floodSpotPlugin_deserialize_from_cdr_buffer(
        floodSpot *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    floodSpotPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    floodSpotPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    floodSpotPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    floodSpotPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    floodSpotPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const floodSpot * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    floodSpotPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    floodSpotPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    floodSpotPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    floodSpotPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const floodSpot *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    floodSpotPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        floodSpot * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    floodSpotPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        floodSpot ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    floodSpotPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        floodSpot *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    floodSpotPlugin_new(void);

    NDDSUSERDllExport extern void
    floodSpotPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobMsdcActLed  */
namespace DdsJobMsdcActServo {

    #define setPhi_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setPhi_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setPhi_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setPhi_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setPhi_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setPhi_req*
    setPhi_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setPhi_req*
    setPhi_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setPhi_req*
    setPhi_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPluginSupport_copy_data(
        setPhi_req *out,
        const setPhi_req *in);

    NDDSUSERDllExport extern void 
    setPhi_reqPluginSupport_destroy_data_w_params(
        setPhi_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setPhi_reqPluginSupport_destroy_data_ex(
        setPhi_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setPhi_reqPluginSupport_destroy_data(
        setPhi_req *sample);

    NDDSUSERDllExport extern void 
    setPhi_reqPluginSupport_print_data(
        const setPhi_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setPhi_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setPhi_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setPhi_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setPhi_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setPhi_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_req *out,
        const setPhi_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setPhi_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setPhi_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setPhi_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setPhi_reqPlugin_deserialize_from_cdr_buffer(
        setPhi_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setPhi_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setPhi_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setPhi_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setPhi_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setPhi_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setPhi_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setPhi_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setPhi_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setPhi_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setPhi_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setPhi_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setPhi_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setPhi_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setPhi_reqPlugin_delete(struct PRESTypePlugin *);

    #define setPhi_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setPhi_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setPhi_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setPhi_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setPhi_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setPhi_reply*
    setPhi_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setPhi_reply*
    setPhi_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setPhi_reply*
    setPhi_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPluginSupport_copy_data(
        setPhi_reply *out,
        const setPhi_reply *in);

    NDDSUSERDllExport extern void 
    setPhi_replyPluginSupport_destroy_data_w_params(
        setPhi_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setPhi_replyPluginSupport_destroy_data_ex(
        setPhi_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setPhi_replyPluginSupport_destroy_data(
        setPhi_reply *sample);

    NDDSUSERDllExport extern void 
    setPhi_replyPluginSupport_print_data(
        const setPhi_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setPhi_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setPhi_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setPhi_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setPhi_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setPhi_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_reply *out,
        const setPhi_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setPhi_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setPhi_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setPhi_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setPhi_replyPlugin_deserialize_from_cdr_buffer(
        setPhi_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setPhi_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setPhi_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setPhi_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setPhi_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setPhi_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setPhi_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setPhi_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setPhi_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setPhi_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setPhi_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setPhi_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setPhi_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setPhi_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setPhi_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setPhi_replyPlugin_delete(struct PRESTypePlugin *);

    #define setTheta_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setTheta_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setTheta_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setTheta_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setTheta_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setTheta_req*
    setTheta_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setTheta_req*
    setTheta_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setTheta_req*
    setTheta_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPluginSupport_copy_data(
        setTheta_req *out,
        const setTheta_req *in);

    NDDSUSERDllExport extern void 
    setTheta_reqPluginSupport_destroy_data_w_params(
        setTheta_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setTheta_reqPluginSupport_destroy_data_ex(
        setTheta_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setTheta_reqPluginSupport_destroy_data(
        setTheta_req *sample);

    NDDSUSERDllExport extern void 
    setTheta_reqPluginSupport_print_data(
        const setTheta_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setTheta_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setTheta_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setTheta_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setTheta_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setTheta_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_req *out,
        const setTheta_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setTheta_req *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_req *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTheta_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setTheta_req *sample); 

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTheta_reqPlugin_deserialize_from_cdr_buffer(
        setTheta_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setTheta_reqPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setTheta_reqPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setTheta_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTheta_reqPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setTheta_reqPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setTheta_req * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setTheta_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setTheta_reqPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTheta_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setTheta_req *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_req * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTheta_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTheta_reqPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_req *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setTheta_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setTheta_reqPlugin_delete(struct PRESTypePlugin *);

    #define setTheta_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define setTheta_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setTheta_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define setTheta_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setTheta_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setTheta_reply*
    setTheta_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setTheta_reply*
    setTheta_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setTheta_reply*
    setTheta_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPluginSupport_copy_data(
        setTheta_reply *out,
        const setTheta_reply *in);

    NDDSUSERDllExport extern void 
    setTheta_replyPluginSupport_destroy_data_w_params(
        setTheta_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setTheta_replyPluginSupport_destroy_data_ex(
        setTheta_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setTheta_replyPluginSupport_destroy_data(
        setTheta_reply *sample);

    NDDSUSERDllExport extern void 
    setTheta_replyPluginSupport_print_data(
        const setTheta_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setTheta_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setTheta_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setTheta_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setTheta_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setTheta_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_reply *out,
        const setTheta_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const setTheta_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_reply *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTheta_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setTheta_reply *sample); 

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTheta_replyPlugin_deserialize_from_cdr_buffer(
        setTheta_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    setTheta_replyPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    setTheta_replyPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    setTheta_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTheta_replyPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    setTheta_replyPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const setTheta_reply * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setTheta_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setTheta_replyPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setTheta_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const setTheta_reply *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_reply * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    setTheta_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setTheta_replyPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        setTheta_reply *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setTheta_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setTheta_replyPlugin_delete(struct PRESTypePlugin *);

    #define thetaPhiPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define thetaPhiPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define thetaPhiPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define thetaPhiPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define thetaPhiPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern thetaPhi*
    thetaPhiPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern thetaPhi*
    thetaPhiPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern thetaPhi*
    thetaPhiPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPluginSupport_copy_data(
        thetaPhi *out,
        const thetaPhi *in);

    NDDSUSERDllExport extern void 
    thetaPhiPluginSupport_destroy_data_w_params(
        thetaPhi *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    thetaPhiPluginSupport_destroy_data_ex(
        thetaPhi *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    thetaPhiPluginSupport_destroy_data(
        thetaPhi *sample);

    NDDSUSERDllExport extern void 
    thetaPhiPluginSupport_print_data(
        const thetaPhi *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    thetaPhiPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    thetaPhiPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    thetaPhiPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    thetaPhiPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    thetaPhiPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        thetaPhi *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        thetaPhi *out,
        const thetaPhi *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const thetaPhi *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        thetaPhi *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    thetaPhiPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const thetaPhi *sample); 

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        thetaPhi **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    thetaPhiPlugin_deserialize_from_cdr_buffer(
        thetaPhi *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    thetaPhiPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    thetaPhiPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    thetaPhiPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    thetaPhiPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    thetaPhiPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const thetaPhi * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    thetaPhiPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    thetaPhiPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    thetaPhiPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const thetaPhi *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        thetaPhi * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    thetaPhiPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        thetaPhi ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    thetaPhiPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        thetaPhi *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    thetaPhiPlugin_new(void);

    NDDSUSERDllExport extern void
    thetaPhiPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobMsdcActServo  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* DdsMsdcPlugin_1182984298_h */

