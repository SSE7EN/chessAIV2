#ifndef _MEMPOOL_HPP_
#define _MEMPOOL_HPP_
/**
**************************
* @file    mempool.hpp
* @author  SE7EN
* @date    2021-05-20
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <cstddef>
#include <stdint.h>




/************************************* Defines *************************************/



/************************************ Structures ***********************************/
template <typename T>
struct mempoolBlockS{
	mempoolBlockS* next; /** ptr to next block */
	mempoolBlockS* prev; /** ptr to previous block */

	T data; /** data */

};

/************************************* Classes *************************************/
template <typename T>
struct mempoolS{
	uint8_t* memory = nullptr; /** pointer to memory */
	mempoolBlockS<T>* freeBlocks = nullptr; /** ptr to first free block */
	mempoolBlockS<T>* allocatedBlocks = nullptr; /** ptr to first alocated block */
	size_t blockSize = 0; /** size of single block  */
	size_t blockCount = 0; /** block count */


};

template <typename T1,typename T2,typename T3,typename T4>
class MempoolManager{
	public:
		MempoolManager();
		~MempoolManager();

		/*
		 * @brief initialize memory pool
		 *
		 * @param blockCount count of block to create
		 *
		 * @return count of block avalible or -1 if sth went wrong
		 *
		 */
		void init(size_t blockCount1,size_t blockCount2,size_t blockCount3,size_t blockCount4);
		void freeBlock(mempoolBlockS<T1> *block);
		mempoolBlockS<T1>* allocateBlock(T1 data);
		mempoolBlockS<T1>* allocateBlock1();
        void freeBlock(mempoolBlockS<T2> *block);
		mempoolBlockS<T2>* allocateBlock(T2 data);
        mempoolBlockS<T2>* allocateBlock2();
        void freeBlock(mempoolBlockS<T3> *block);
		mempoolBlockS<T3>* allocateBlock(T3 data);
        mempoolBlockS<T3>* allocateBlock3();
        void freeBlock(mempoolBlockS<T4> *block);
		mempoolBlockS<T4>* allocateBlock(T4 data);
		mempoolBlockS<T4>* allocateBlock4();

			


	private:
		mempoolS<T1> mempool1;
		mempoolS<T2> mempool2;
		mempoolS<T3> mempool3;
		mempoolS<T4> mempool4;
};






#endif